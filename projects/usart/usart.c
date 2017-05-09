#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>


#include <stdio.h>
#include <errno.h>


#include "../../libs/ringbuffer/ringbuffer.h"


int _write(int file, char *ptr, int len);

static void clock_setup(void)
{
  rcc_clock_setup_in_hse_8mhz_out_72mhz();

  /* Enable clocks for GPIO port A (for GPIO_USART3_TX) and USART3. */

  rcc_periph_clock_enable(RCC_AFIO);
  rcc_periph_clock_enable(RCC_USART3);

  //rcc_peripheral_enable_clock(&RCC_APB2ENR, GPIOB);
  rcc_periph_clock_enable(RCC_GPIOB);
}


static void gpio_setup(void)
{
  /* Enable GPIOC clock. */
  //rcc_peripheral_enable_clock(&RCC_APB2ENR, GPIOС);
  rcc_periph_clock_enable(RCC_GPIOC);

  /* Set GPIO13 (in GPIO port C) to 'output push-pull' for the LEDs. */
  gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
          GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
}

#define BUFFER_SIZE 1024

struct ring output_ring;
uint8_t output_ring_buffer[BUFFER_SIZE];


static void usart_setup(void) {
  /* Initialize output ring buffer. */
  ring_init(&output_ring, output_ring_buffer, BUFFER_SIZE);

  /* Enable the USART3 interrupt. */
  nvic_enable_irq(NVIC_USART3_IRQ);

  /* Setup GPIO pin GPIO_USART3_TX on GPIO port B for transmit. */
  gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
          GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART3_TX);

  /* Setup GPIO pin GPIO_USART3_RX on GPIO port B for receive. */
  gpio_set_mode(GPIOB, GPIO_MODE_INPUT,
          GPIO_CNF_INPUT_FLOAT, GPIO_USART3_RX);

  /* Setup UART parameters. */
  usart_set_baudrate(USART3, 9600);
  usart_set_databits(USART3, 8);
  usart_set_stopbits(USART3, USART_STOPBITS_1);
  usart_set_parity(USART3, USART_PARITY_NONE);
  usart_set_flow_control(USART3, USART_FLOWCONTROL_NONE);
  usart_set_mode(USART3, USART_MODE_TX_RX);

  /* Enable USART3 Receive interrupt. */
  USART_CR1(USART3) |= USART_CR1_RXNEIE;

  /* Finally enable the USART. */
  usart_enable(USART3);
}


//ringbuffer example

void usart3_isr(void) {
  // Check if we were called because of RXNE.
  if (((USART_CR1(USART3) & USART_CR1_RXNEIE) != 0) &&
      ((USART_SR(USART3) & USART_SR_RXNE) != 0)) {

    // Indicate that we got data.
    gpio_toggle(GPIOC, GPIO13);

    // Retrieve the data from the peripheral.
    uint8_t data = usart_recv(USART3);
    ring_write_ch(&output_ring, data);

    // Enable transmit interrupt so it sends back the data.
    USART_CR1(USART3) |= USART_CR1_TXEIE;
  }

  // Check if we were called because of TXE.
  if (((USART_CR1(USART3) & USART_CR1_TXEIE) != 0) &&
      ((USART_SR(USART3) & USART_SR_TXE) != 0)) {

    int32_t data;
    //gpio_toggle(GPIOC, GPIO13);

    data = ring_read_ch(&output_ring, NULL);

    if (data == -1) {
      // Disable the TXE interrupt, it's no longer needed.
      USART_CR1(USART3) &= ~USART_CR1_TXEIE;
    } else {
      // Put data into the transmit register.
      usart_send(USART3, data);
    }
  }
}


//echo example
/*
void usart3_isr(void) {
  static uint8_t data = 'A';

  // Check if we were called because of RXNE.
  if (((USART_CR1(USART3) & USART_CR1_RXNEIE) != 0) &&
      ((USART_SR(USART3) & USART_SR_RXNE) != 0)) {

    // Indicate that we got data.
    gpio_toggle(GPIOC, GPIO13);

    // Retrieve the data from the peripheral.
    data = usart_recv(USART3);

    // Enable transmit interrupt so it sends back the data.
    USART_CR1(USART3) |= USART_CR1_TXEIE;
  }

  // Check if we were called because of TXE.
  if (((USART_CR1(USART3) & USART_CR1_TXEIE) != 0) &&
      ((USART_SR(USART3) & USART_SR_TXE) != 0)) {

    // Disable the TXE interrupt as we don't need it anymore.
    USART_CR1(USART3) &= ~USART_CR1_TXEIE;

    // Indicate that we are sending out data.
    gpio_toggle(GPIOC, GPIO13);

    //  Put data into the transmit register.
    usart_send(USART3, data);
  }
}
*/

/*
int _write(int file, char *ptr, int len)
{
  int ret;

  if (file == 1) {
    ret = ring_write(&output_ring, (uint8_t *)ptr, len);

    if (ret < 0)
      ret = -ret;

    USART_CR1(USART3) |= USART_CR1_TXEIE;

    return ret;
  }

  errno = EIO;
  return -1;
}
*/

static void systick_setup(void)
{
  /* 72MHz / 8 => 9000000 counts per second. */
  systick_set_clocksource(STK_CSR_CLKSOURCE_AHB_DIV8);

  /* 9000000/9000 = 1000 overflows per second - every 1ms one interrupt */
  /* SysTick interrupt every N clock pulses: set reload to N-1 */
  systick_set_reload(8999);

  systick_interrupt_enable();

  /* Start counting. */
  systick_counter_enable();
}

void sys_tick_handler(void)
{
  static int counter = 0;
  static float fcounter = 0.0;
  static double dcounter = 0.0;
  static uint32_t temp32 = 0;
  static uint32_t led = 0;
  static int c;

  int ret;

  temp32++;

  /*
   * We call this handler every 1ms so we are sending hello world
   * every 100ms / 10Hz.
   */
  if (temp32 == 100) {
    temp32 = 0;
    //printf("Hello World! %i %f %f\r\n", counter, fcounter, dcounter);
    counter++;
    fcounter += 0.01;
    dcounter += 0.01;

    char tx = c + '0';

    ret = ring_write_ch(&output_ring, tx);
    c = (c == 9) ? 0 : c + 1;//next digit
    if(( counter++ % 80) == 0){
      ret = ring_write_ch(&output_ring, '\r');
      ret = ring_write_ch(&output_ring, '\n');
    }
    //enable write
    USART_CR1(USART3) |= USART_CR1_TXEIE;


    led++;
    if(led == 5){
      //gpio_clear(GPIOC, GPIO13);
      //ret = ring_write(&output_ring, tx, 8);
      gpio_toggle(GPIOC, GPIO13);
      led = 0;
    }
  }
}


int main(void){



  clock_setup();
  gpio_setup();
  usart_setup();
  gpio_set(GPIOC, GPIO13);
  //systick_setup();


  //simple mode
  /*
  int i, j = 0, c = 0;

  while (1) {
    // Blink the LED (PC13) on the board with every transmitted byte.
    gpio_toggle(GPIOC, GPIO13);  // LED on/off
    usart_send_blocking(USART3, c + '0'); // USART2: Send byte.
    c = (c == 9) ? 0 : c + 1; // Increment c.
    if ((j++ % 80) == 0) {  // Newline after line full.
      usart_send_blocking(USART3, '\r');
      usart_send_blocking(USART3, '\n');
    }
    for (i = 0; i < 800000; i++)  // Wait a bit.
      __asm__("nop");
  }*/

  while(1) {
    __asm__("nop");
  }

}

