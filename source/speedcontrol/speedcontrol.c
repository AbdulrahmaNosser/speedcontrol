#include <stdint.h>

#include "speedcontrol.h"
#include "../switch/switch.h"

static uint8_t motor_speed = MID_SPEED;

void motor_init (void)
{
    motor_speed = MID_SPEED;
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

void motor_cmd (SWITCH_STATE_t state_of_switch)
{
    switch (state_of_switch)
    {
    case VE_POS_PREPRESSED:
        if (motor_speed == MIN_SPEED)
        {
            motor_set (MID_SPEED);
        }

        else if (motor_speed == MID_SPEED)
        {
            motor_set (MAX_SPEED);
        }
        
        else
        {
            
        }
        break;
    }    
}

uint8_t motor_speed_get (void)
{
    return motor_speed;
}