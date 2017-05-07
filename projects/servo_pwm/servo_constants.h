#ifndef SERVO_CONSTANTS_H
#define SERVO_CONSTANTS_H


/**
 * Prescale 72000000 Hz system clock by 72 = 1000000 Hz.
 * use 72-1 per https://github.com/libopencm3/libopencm3-examples/issues/140
 */
#define PWM_PRESCALE  (71) 

/**
 * We need a 50 Hz period (1000 / 20ms = 50), thus divide 100000 by 50 = 20000 (us).
 */
#define PWM_PERIOD    (20000)

/**
 * Max. pos. at 2050 us (2.00ms).
 */
#define SERVO_MAX   (2050)

/**
 * Min. pos. at 950  us (0.95ms).
 */
#define SERVO_MIN   (950)

/**
 * Middle pos. at 1580 us (1.58ms).
 */
#define SERVO_NULL    (1580)



#endif