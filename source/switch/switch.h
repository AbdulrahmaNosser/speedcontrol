#ifndef SWITCH_H
#define SWITCH_H


typedef enum
{   
    PB_PRESSURE,
    PB_MINUS,
    PB_PLUS
}t_SWITCH;

typedef enum
{
    PB_RELEASED,
    PB_PRE_PRESSED,
    PB_PRESSED,
    PB_PRE_RELEASED
}t_SWITCH_STATE;


t_SWITCH sw_get_name(void);
t_SWITCH_STATE sw_get_state(void);

#endif
