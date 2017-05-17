#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>


#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "../../libs/macros.h"
#include "../../libs/microrl/microrl.h"
#include "readline_context.h"



int _write(int file, char *ptr, int len);

static void clock_setup(void) {
  rcc_clock_setup_in_hse_8mhz_out_72mhz();

  /* Enable clocks for GPIO port A (for GPIO_USART3_TX) and USART3. */

  rcc_periph_clock_enable(RCC_AFIO);
  rcc_periph_clock_enable(RCC_USART3);

  //rcc_peripheral_enable_clock(&RCC_APB2ENR, GPIOB);
  rcc_periph_clock_enable(RCC_GPIOB);
}



static void gpio_setup(void) {
  /* Enable GPIOC clock. */
  //rcc_peripheral_enable_clock(&RCC_APB2ENR, GPIOС);
  rcc_periph_clock_enable(RCC_GPIOC);

  /* Set GPIO13 (in GPIO port C) to 'output push-pull' for the LEDs. */
  gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
          GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
}



static void usart_setup(readline_context_t *ctx) {
  /* Initialize output ring buffer. */
  ring_init(&ctx->output_ring, ctx->output_ring_buffer, BUFFER_SIZE);

  /* Enable the USART3 interrupt. */
  nvic_enable_irq(NVIC_USART3_IRQ);

  /* Setup GPIO pin GPIO_USART3_TX on GPIO port B for transmit. */
  gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
          GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART3_TX);

  /* Setup GPIO pin GPIO_USART3_RX on GPIO port B for receive. */
  gpio_set_mode(GPIOB, GPIO_MODE_INPUT,
          GPIO_CNF_INPUT_FLOAT, GPIO_USART3_RX);

  /* Setup UART parameters. */
  usart_set_baudrate(USART3, 115200);
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


static readline_context_t g_context;


void usart3_isr(void) {
  // Check if we were called because of RXNE.
  if (((USART_CR1(USART3) & USART_CR1_RXNEIE) != 0) &&
      ((USART_SR(USART3) & USART_SR_RXNE) != 0)) {

    // Retrieve the data from the peripheral.
    uint8_t data = usart_recv(USART3);
    microrl_insert_char(&g_context.readline, data);

    // Enable transmit interrupt so it sends back the data.
    USART_CR1(USART3) |= USART_CR1_TXEIE;
  }

  // Check if we were called because of TXE.
  if (((USART_CR1(USART3) & USART_CR1_TXEIE) != 0) &&
      ((USART_SR(USART3) & USART_SR_TXE) != 0)) {

    int32_t data;

    data = ring_read_ch(&g_context.output_ring, NULL);

    if (data == -1) {
      // Disable the TXE interrupt, it's no longer needed.
      USART_CR1(USART3) &= ~USART_CR1_TXEIE;
    } else {
      // Put data into the transmit register.
      usart_send(USART3, data);
    }
  }
}



//10 Hz = 1000/100
#define EVENT_INTERVAL 10
#define LED_1SEC (1000/EVENT_INTERVAL)

static volatile int32_t led;

static int usart_write(struct ring *ring, const char *ptr, int len){
  int ret;
  ret = ring_write(ring, (uint8_t *)ptr, len);

  if (ret < 0) {
    ret = -ret;

    //notify error
    led = LED_1SEC;
    gpio_clear(GPIOC, GPIO13);
  }

  USART_CR1(USART3) |= USART_CR1_TXEIE;

  return ret;
}


int _write(int file, char *ptr, int len) {

  if (file == 1) {
    return usart_write(&g_context.output_ring, ptr, len);
  }

  errno = EIO;
  return -1;
}


static void usart_print_callback(microrl_t *this, const char * str){
    readline_context_t *ctx = container_of(this, readline_context_t, readline);
    usart_write(&ctx->output_ring, str, strlen(str));
}


//setup systick timer
static void systick_setup(void) {
  /* 72MHz / 8 => 9000000 counts per second. */
  systick_set_clocksource(STK_CSR_CLKSOURCE_AHB_DIV8);

  /* 9000000/9000 = 1000 overflows per second - every 1ms one interrupt */
  /* SysTick interrupt every N clock pulses: set reload to N-1 */
  systick_set_reload(8999);

  systick_interrupt_enable();

  /* Start counting. */
  systick_counter_enable();
}


//led blink, common event timer

void sys_tick_handler(void) {
  static uint32_t temp32 = 0;

  temp32++;

  /*
   * We call this handler every 1ms so we are sending hello world
   * every 100ms / 10Hz.
   */
  if (temp32 == EVENT_INTERVAL) {
    temp32 = 0;

    if(led>0){
      led--;
      if(led==0){
        gpio_set(GPIOC, GPIO13);
      }
    }

  }
}


int main(void){
  clock_setup();
  gpio_setup();

  led = 10;

  readline_context_init(&g_context, usart_print_callback);

  usart_setup(&g_context);
  systick_setup();

  gpio_clear(GPIOC, GPIO13);
  printf("%s\n", "Hello, readline");

  while(1) {
    __asm__("nop");
  }

}

