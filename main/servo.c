// Servo Control for SG90 (0 to 180 degree)
// MIT License Fonger

// Connect signal pin to NodeMCU D7 (GPIO13)
// add EXTRA_COMPONENTS = extras/pwm to makefile
#include <stdio.h>
#include <driver/pwm.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>


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
  const uint32_t pin[1] = {13};
  uint32_t duty[1] = {0};
  printf("pwm_init(1, [13])\n");
  pwm_init(20000, duty, 1, pin); //20000 us == 50Hz frequency w/ duty cycle 0 on pwm channel 1, pin 13
  pwm_start();
  
}

void servo_toggle(){
    
    /*for (int i = 180; i >= 0; i--) {
      pwm_set_duty(0,get_servo_duty_cycle(i));
      pwm_set_phase(0,0);
      pwm_start();
      vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    
    vTaskDelay(500 / portTICK_PERIOD_MS);
    for (int i = 0; i <= 180; i++) {
      
      pwm_set_duty(0,get_servo_duty_cycle(i));
      pwm_set_phase(0,0);
      pwm_start();
      vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    */
     pwm_set_duty(0,2500);
     pwm_set_phase(0,0);
     pwm_start();
     vTaskDelay(500/portTICK_PERIOD_MS);
     pwm_set_duty(0,1200);
     pwm_set_phase(0,0);
     pwm_start();
     vTaskDelay(500/portTICK_PERIOD_MS);
     pwm_set_duty(0,2500);
     pwm_set_phase(0,0);
     pwm_start();
}

