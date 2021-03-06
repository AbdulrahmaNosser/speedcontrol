#ifndef SPEEDCONTROL_H
#define SPEEDCONTROL_H

#include <stdint.h>

#include "../switch/switch.h"

#define MIN_SPEED 140
#define MID_SPEED 90
#define MAX_SPEED 10

typedef enum
{
    SPEED_MINUS,
    SPEED_PLUS,
    STATUS_QOU
}t_SPEED_ACTION;

void motor_init (void);
void motor_set (uint8_t speed);
uint8_t motor_get (void); 
void motor_update (t_SWITCH sw_name, t_SWITCH_STATE sw_state, uint8_t sw_duration);
static void logic_sw_pressure(t_SWITCH_STATE sw_state, uint8_t sw_duration);

void read_switch (void);
void generate_cmd (t_SWITCH name_of_switch, t_SWITCH_STATE state_of_switch);
void motor_cmd (t_SPEED_ACTION action);
t_SPEED_ACTION cmd_get (void);

#endif