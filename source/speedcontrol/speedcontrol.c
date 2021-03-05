#include <stdint.h>

#include "speedcontrol.h"

static uint8_t motor_speed = 0;

void motor_init (void)
{
    motor_speed = MID_SPEED;
}

uint8_t motor_speed_get (void)
{
    return motor_speed;
}