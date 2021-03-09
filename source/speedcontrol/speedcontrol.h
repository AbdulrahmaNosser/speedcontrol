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

void MotorInit (void);
void MotorSet (uint8_t speed);
uint8_t MotorGet (void); 
void MotorUpdate (t_SWITCH sw_name, t_SWITCH_STATE sw_state, uint8_t sw_duration);
static void Logic_SW_Pressure(t_SWITCH_STATE sw_state, uint8_t sw_duration);
static void Logic_SW_Minus(t_SWITCH_STATE sw_state);
static void Logic_SW_Plus(t_SWITCH_STATE sw_state);

#endif