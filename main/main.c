#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "../lib/usb_host_handler.h"

void app_main(void)
{
    usb_host_handler_init();
}
