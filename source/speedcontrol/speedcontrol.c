#include <stdint.h>

#include "speedcontrol.h"
#include "../switch/switch.h"

static uint8_t motor_speed = MID_SPEED;
static t_SPEED_ACTION action = -1;

void motor_init (void)
{
    motor_speed = MID_SPEED;
    t_SPEED_ACTION action = -1;
}

void generate_cmd (t_SWITCH name_of_switch, t_SWITCH_STATE state_of_switch)
{
    switch (name_of_switch)
    {
    case PB_PRESSURE:
        if (state_of_switch == PB_PRE_PRESSED)
        {
            if (motor_speed == MID_SPEED || motor_speed == MAX_SPEED )
            {
                action = SPEED_MINUS;
            }
            else 
            {
                action = STATUS_QOU;
            }
        }
        else
        {
            action = STATUS_QOU;
        }
        break;
    
    default:
        action = STATUS_QOU;
        break;
    }
}

void motor_set (uint8_t speed)
{
    if (speed == MIN_SPEED || speed == MID_SPEED || speed == MAX_SPEED )
    {
        motor_speed = speed;
    }
    else
    {
    }
}


void motor_cmd (t_SPEED_ACTION action)
{
    
}


uint8_t motor_speed_get (void)
{
    return motor_speed;
}

t_SPEED_ACTION cmd_get (void)
{
    return action;
}