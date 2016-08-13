#ifndef USB_CDCACM_H
#define USB_CDCACM_H

#include <libopencm3/usb/usbd.h>

usbd_device* init_usb_cdcacm(void);

#endif
