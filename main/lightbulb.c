/*
 * ESPRESSIF MIT License
 *
 * Copyright (c) 2018 <ESPRESSIF SYSTEMS (SHANGHAI) PTE LTD>
 *
 * Permission is hereby granted for use on ESPRESSIF SYSTEMS products only, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

/* HomeKit Lightbulb Example Dummy Implementation
 * Refer ESP IDF docs for LED driver implementation:
 * https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/ledc.html
 * https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/rmt.html
*/

#include <stdio.h>
#include <stdbool.h>
#include "esp_log.h"
#include "servo.h"
#include "sense.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
static const char *TAG = "lightbulb";

/**
 * @brief initialize the lightbulb lowlevel module
 */
void lightbulb_init(void)
{   
    servo_init();
    adc_setup();
    ESP_LOGI(TAG, "Initializing PWM Driver");
}

/**
 * @brief turn on/off the lowlevel lightbulb
 */
int lightbulb_set_on(bool value)
{
    
    int i = 0;
    /*while(state_check() != value && i < 3){
        ESP_LOGI(TAG, "lightbulb_set_on : %s", value == true ? "true" : "false");
        servo_toggle();
        i++;
    }*/
    if(state_check()!= value){
        //ESP_LOGI(TAG, "lightbulb_set_on : %s", value == true ? "true" : "false");
        servo_toggle();
        i++;
    }

    return 0;
}
