#ifndef USB_CDCACM_H
#define USB_CDCACM_H

#include <libopencm3/usb/usbd.h>

void init_usb_cdcacm(void);

void usb_poll_loop(void);

#endif
