#ifndef SPEEDCONTROL_H
#define SPEEDCONTROL_H

#include <stdint.h>

#define MIN_SPEED 140
#define MID_SPEED 90
#define MAX_SPEED 10


void motor_init (void);
uint8_t motor_speed_get (void);

#endif