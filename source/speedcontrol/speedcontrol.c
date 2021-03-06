#include <stdint.h>

#include "speedcontrol.h"
#include "../switch/switch.h"

static uint8_t motor_speed = MID_SPEED;
static t_SPEED_ACTION action = STATUS_QOU;

void motor_init (void)
{
    motor_speed = MID_SPEED;
    action = STATUS_QOU;
}

void motor_set (uint8_t speed)
{
    if (speed == MIN_SPEED || speed == MID_SPEED || speed == MAX_SPEED)
    {
        motor_speed = speed;
    }
    else
    {

    }
}

uint8_t motor_get (void)
{
    return motor_speed;
}

void motor_update (t_SWITCH sw_name, t_SWITCH_STATE sw_state, uint8_t sw_duration)
{
    switch (sw_name)
    {
    case SW_PRESSURE:
        logic_sw_pressure(sw_state, sw_duration);
        break;

    case SW_MINUS:
        break;
    
    case SW_PLUS:
        break;

    default:
        break;
    }
}

static void logic_sw_pressure(t_SWITCH_STATE sw_state, uint8_t sw_duration)
{
    if (sw_state == SW_S_PRESSED)
    {
        if (sw_duration >= 30)
        {
            if (motor_speed == MAX_SPEED)
            {
                motor_speed = MID_SPEED;
            }
            else if (motor_speed == MID_SPEED)
            {
                motor_speed = MIN_SPEED;
            }
            else{}
        }
        else{}
    }
    else{}
}