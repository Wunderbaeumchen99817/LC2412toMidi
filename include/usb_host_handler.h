/*
 * usb_host_handler.h
 *
 *  Author: Wunderbaeumchen99817
 */

#ifndef USB_HOST_HANDLER_H_
#define USB_HOST_HANDLER_H_

#include "usb/usb_host.h"

#define DAEMON_TASK_PRIORITY    2
#define CLASS_TASK_PRIORITY     3

extern void usb_host_handler_init(void);


#endif /* USB_HOST_HANDLER_H_ */
