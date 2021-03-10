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


void SW_Read(void);
t_SWITCH SW_GetName(void);
t_SWITCH_STATE SW_GetState(void);
uint16_t SW_GetDuration(void);

#endif
