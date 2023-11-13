/*
 * midi_handler.c
 *
 *      Author: Wunderbaeumchen99817
 */

#include "midi_handler.h"

#include <stdlib.h>
#include "esp_log.h"

static const char *TAG = "MIDI";

static QueueHandle_t midi_queue_hdl;

static void message_control_change(midi_message_t *message) {
	uint8_t second_byte = message->bytes[2];
	uint8_t third_byte = message->bytes[3];
	printf("%d %d\n", second_byte, third_byte);
}

void midi_usb_host_task(void *arg) {
	midi_message_t message_obj;
	midi_queue_hdl = xQueueCreate(4, sizeof(midi_message_t));

	while(1) {
		if(xQueueReceive(midi_queue_hdl, &message_obj, portMAX_DELAY)) {
			if(message_obj.bytes[1] == 176) {
				message_control_change(&message_obj);
			}
			/*printf("%d %d %d %d \n",
					message_obj.bytes[0],
					message_obj.bytes[1],
					message_obj.bytes[2],
					message_obj.bytes[3]);
			*/
		}
	}
}

QueueHandle_t get_midi_queue_hdl(void) {
	return midi_queue_hdl;
}
