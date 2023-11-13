/*
 * midi_handler.h
 *
 *  Author: Wunderbaeumchen99817
 */

#ifndef MIDI_HANDLER_H_
#define MIDI_HANDLER_H_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

typedef struct {
	uint8_t bytes[4];
} midi_message_t;

#define MIDI_TASK_PRIORITY 4

extern void midi_usb_host_task(void *arg);
extern QueueHandle_t get_midi_queue_hdl(void);
#endif /* MIDI_HANDLER_H_ */
