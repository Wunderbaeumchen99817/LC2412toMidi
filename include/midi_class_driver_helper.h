/*
 * midi_class_driver_helper.h
 *
 *  Created on: 11.11.2023
 *      Author: Katharina
 */

#ifndef MIDI_CLASS_DRIVER_HELPER_H_
#define MIDI_CLASS_DRIVER_HELPER_H_

#include <stdlib.h>
#include "usb/usb_host.h"

typedef struct {
	uint8_t interface_nmbr;
	uint8_t alternate_setting;
} interface_config_t;

extern void midi_class_helper_get_interface_settings(const usb_config_desc_t *usb_conf, interface_config_t *interface_conf);



#endif /* MIDI_CLASS_DRIVER_HELPER_H_ */
