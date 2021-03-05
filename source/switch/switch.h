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

typedef enum
{
    SPEED_MINUS,
    SPEED_PLUS,
    STATUS_QOU
}t_SPEED_ACTION;

#endif
