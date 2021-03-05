#ifndef SPEEDCONTROL_H
#define SPEEDCONTROL_H

#include <stdint.h>

#include "../switch/switch.h"

#define MIN_SPEED 140
#define MID_SPEED 90
#define MAX_SPEED 10


void motor_init (void);
void read_switch (void);
void motor_set (uint8_t speed);
void generate_cmd (t_SWITCH name_of_switch, t_SWITCH_STATE state_of_switch);
void motor_cmd (t_SPEED_ACTION action);
uint8_t motor_speed_get (void);
t_SPEED_ACTION cmd_get (void);

#endif