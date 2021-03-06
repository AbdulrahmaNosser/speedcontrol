#ifndef SWITCH_H
#define SWITCH_H

#include <stdint.h>

typedef enum
{   
    SW_PRESSURE,
    SW_MINUS,
    SW_PLUS
}t_SWITCH;

typedef enum
{
    SW_S_RELEASED,
    SW_S_PRE_PRESSED,
    SW_S_PRESSED,
    SW_S_PRE_RELEASED
}t_SWITCH_STATE;

static t_SWITCH_STATE state_of_switch;
static uint8_t duration_of_switch;

t_SWITCH sw_get_name(void);
t_SWITCH_STATE sw_get_state(void);
uint8_t sw_get_pressed_duration(void);

#endif
