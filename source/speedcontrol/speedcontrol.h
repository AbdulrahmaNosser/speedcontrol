#ifndef SPEEDCONTROL_H
#define SPEEDCONTROL_H

#include <stdint.h>

#include "../switch/switch.h"

#define MIN_SPEED 140
#define MID_SPEED 90
#define MAX_SPEED 10


void motor_init (void);
void motor_set (uint8_t speed);
void motor_cmd (SWITCH_STATE_t state_of_switch);
uint8_t motor_speed_get (void);

#endif