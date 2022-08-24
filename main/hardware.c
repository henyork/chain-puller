#include <driver/adc.h>
#include "esp_log.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/pwm.h>
#include <stdio.h>

int x;
uint16_t adc_data[100];
static const char *TAG = "adc sense";
void adc_setup(){

    adc_config_t adc_config;

    // Depend on menuconfig->Component config->PHY->vdd33_const value
    // When measuring system voltage(ADC_READ_VDD_MODE), vdd33_const must be set to 255.
    adc_config.mode = ADC_READ_TOUT_MODE;
    adc_config.clk_div = 8; // ADC sample collection clock = 80MHz/clk_div = 10MHz
    ESP_ERROR_CHECK(adc_init(&adc_config));
    
}

int state_check(){
    int state;
    if (ESP_OK == adc_read(&adc_data[0])) {
            //ESP_LOGI(TAG, "adc read: %d\r\n", adc_data[0]);
        }
    if(adc_data[0]>800){
        state =1; // light is on currently
    }else if(adc_data[0]<400){
        state = 0; // light is off currently
    }else{
        state = -1; //unknown state or error
    }
    return state;
}


uint32_t duty[1];


inline uint32_t get_servo_duty_cycle(double angle) {
  uint32_t duty;
  if (angle > 180){
      duty = -1;
  }else{
      duty = (uint32_t)((0.025 + (0.12 - 0.025) * (angle / 180.0)) *
                    65536);
  }
  return duty;
}

void servo_init() {
  const uint32_t pin[1] = {13}; //pwm on pin 13 (D7)
  uint32_t duty[1] = {0};
  printf("pwm_init(1, [13])\n");
  pwm_init(20000, duty, 1, pin); //20000 us == 50Hz frequency w/ duty cycle 0 on pwm channel 1, pin 13
  pwm_start();
  
}

void servo_toggle(){
   
     pwm_set_duty(0,2500);
     pwm_set_phase(0,0);
     pwm_start();
     vTaskDelay(800/portTICK_PERIOD_MS);
     pwm_set_duty(0,1900);
     pwm_set_phase(0,0);
     pwm_start();
     vTaskDelay(800/portTICK_PERIOD_MS);
     pwm_set_duty(0,2500);
     pwm_set_phase(0,0);
     pwm_start();


     pwm_set_duty(0,2500);
     pwm_set_phase(0,0);
     pwm_start();
     vTaskDelay(800/portTICK_PERIOD_MS);
     pwm_set_duty(0,1200);
     pwm_set_phase(0,0);
     pwm_start();
     vTaskDelay(800/portTICK_PERIOD_MS);
     pwm_set_duty(0,2500);
     pwm_set_phase(0,0);
     pwm_start();
     vTaskDelay(800/portTICK_PERIOD_MS);
     pwm_stop(0);
}

