/*
 * midi_class_driver_helper.c
 *
 *  Created on: 11.11.2023
 *      Author: Katharina
 */

#include "midi_class_driver_helper.h"

#include "esp_log.h"
static const char *TAG = "CLASS HELPER";

void midi_class_helper_get_interface_settings(const usb_config_desc_t *usb_conf, interface_config_t *interface_conf) {
	assert(usb_conf != NULL);
	assert(interface_conf != NULL);

	ESP_LOGI(TAG, "Getting interface config");

	int offset = 0;
	    uint16_t wTotalLength = usb_conf->wTotalLength;
	    const usb_standard_desc_t *next_desc = (const usb_standard_desc_t *)usb_conf;

	    do {
	    	if(next_desc->bDescriptorType == USB_B_DESCRIPTOR_TYPE_INTERFACE) {
	    		usb_intf_desc_t *interface_desc = (usb_intf_desc_t *)next_desc;

	    		//check if there are >0 endpoints
	    		if(interface_desc->bNumEndpoints > 0) {
	    			//use interface
	    			interface_conf->interface_nmbr = interface_desc->bInterfaceNumber;
	    			interface_conf->alternate_setting = interface_desc->bAlternateSetting;

	    			printf("Interface Number: %d, Alternate Setting: %d \n", interface_conf->interface_nmbr, interface_conf->alternate_setting);

	    		}
	    	}
	    	if(next_desc->bDescriptorType == USB_B_DESCRIPTOR_TYPE_ENDPOINT) {
	    		usb_ep_desc_t *ep_desc = (usb_ep_desc_t *)next_desc;
	    		if(USB_EP_DESC_GET_EP_DIR(ep_desc)) {
	    			//endpoint is IN
	    			interface_conf->endpoint_address = ep_desc->bEndpointAddress;
	    			interface_conf->max_packet_size = ep_desc->wMaxPacketSize;
	    			printf("endpoint address: %d , mps: %d\n", interface_conf->endpoint_address, interface_conf->max_packet_size);
	    		}
	    	}

	        next_desc = usb_parse_next_descriptor(next_desc, wTotalLength, &offset);

	    } while (next_desc != NULL);
}
