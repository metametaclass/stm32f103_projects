#ifndef USB_CDCACM_H
#define USB_CDCACM_H

#include <libopencm3/usb/usbd.h>

#include <inttypes.h>
#include <stdint.h>

typedef struct usb_cdcacm_context_s usb_cdcacm_context_t;

typedef void (*on_usb_callback_t)(usb_cdcacm_context_t *ctx, int len, char *buffer);

struct usb_cdcacm_context_s {
    on_usb_callback_t on_read;
    usbd_device *usbd_dev;
};


void usb_cdcacm_init(usb_cdcacm_context_t *ctx, on_usb_callback_t on_read);

void usb_cdcacm_poll_loop(usb_cdcacm_context_t *ctx);

void usb_print(usb_cdcacm_context_t *ctx, const char *str, size_t len);

void usb_prints(usb_cdcacm_context_t *ctx, const char *str);

#endif
