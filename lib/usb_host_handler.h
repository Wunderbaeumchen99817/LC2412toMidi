/*
 * usb_host_handler.h
 *
 *  Created on: 05.11.2023
 *      Author: Katharina
 */

#ifndef USB_HOST_HANDLER_H_
#define USB_HOST_HANDLER_H_

#include "usb/usb_host.h"
#include "usb/hid_host.h"

extern void hid_host_interface_callback(hid_host_device_handle_t hid_device_handle,
                                 const hid_host_interface_event_t event,
                                 void *arg);
extern void hid_host_device_event(hid_host_device_handle_t hid_device_handle,
                           const hid_host_driver_event_t event,
                           void *arg);
extern void hid_host_task(void *pvParameters);
extern void hid_host_device_callback(hid_host_device_handle_t hid_device_handle,
        const hid_host_driver_event_t event,
        void *arg);
extern void usb_host_handler_init(void);

#endif /* USB_HOST_HANDLER_H_ */
