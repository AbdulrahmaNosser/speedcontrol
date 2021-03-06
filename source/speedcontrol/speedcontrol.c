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
