// -*- mode:c++; mode: flymake -*-
#include <PowerFunctions.h>



/*** 
 * This demo uses an arduino to drive a 
 * LEGO RC Tracked Racer 42065
 * We go forward a bit then backward
 * This is only a test sketch to test infrared-circuit on pin 12
 * DEfault channel is 1 (Channel 'Zero' on pdf)
 */

PowerFunctions pf(12, 0);

/* See http://en.cppreference.com/w/cpp/utility/variadic

void vararg(uint8_t  commands...) {
      va_list args;
      va_start(args, commands);
      uint8_t current=va_arg(args,uint8_t);      
      va_end(args);
}
*/

void setup() {

  
}


void goForward(uint16_t time){
  pf.combo_pwm(PWM_FWD2, PWM_REV2);
  delay(time);
  pf.combo_pwm(PWM_BRK,PWM_BRK);
  pf.combo_pwm(PWM_FLT,PWM_FLT);
}


void goBackward(uint16_t time){
  pf.combo_pwm(PWM_REV2, PWM_FWD2);
  delay(time);
  pf.combo_pwm(PWM_BRK,PWM_BRK);
  pf.combo_pwm(PWM_FLT,PWM_FLT);
}

void loop() {
  // put your main code here, to run repeatedly:
  goForward(1500);
  goBackward(500);
  while(true) { delay(1000); }
  
}





void step(uint8_t output, uint8_t pwm,  uint16_t time) {
  pf.single_pwm(output, pwm);
  delay(time);
  pf.single_pwm(output, PWM_BRK);
  delay(30);
  pf.single_pwm(output, PWM_FLT);
}
