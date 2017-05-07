#include "utils.h"


/**
 * Delay by executing some "nop"s.
 *
 * @param[in] d number of "nop"s to perform.
 */
void delay(int d)
{

     int i;

     for(i = 0; i < d; i++) {
          __asm("nop");
     }
}

