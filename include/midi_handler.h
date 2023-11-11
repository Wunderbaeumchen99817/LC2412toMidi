/*
 * midi_handler.h
 *
 *  Created on: 11.11.2023
 *      Author: Katharina
 */

#ifndef MIDI_HANDLER_H_
#define MIDI_HANDLER_H_

#include "usb/usb_host.h"

extern void midi_usb_host_callback(usb_transfer_t *transfer);

#endif /* MIDI_HANDLER_H_ */
