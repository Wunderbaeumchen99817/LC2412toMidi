/*
 * midi_handler.c
 *
 *  Created on: 11.11.2023
 *      Author: Katharina
 */

#include "midi_handler.h"

#include <stdlib.h>

#define MESSAGE_LENGTH 4

static const char *TAG = "MIDI";


void midi_usb_host_callback(usb_transfer_t *transfer) {

	int size = (int)transfer->actual_num_bytes;
	//one message contains 4 bytes of data
	int num_messages = size/MESSAGE_LENGTH;

	int offset = 0;
	//print messages
	for(int i = 0; i < num_messages; i++) {
		for (int j = 0; j < MESSAGE_LENGTH; j++) {
			printf("%d ", transfer->data_buffer[j+offset]);
		}
		printf("\n");
		offset += MESSAGE_LENGTH;
	}
	ESP_ERROR_CHECK(usb_host_transfer_submit(transfer));
}
