#include "switch.h"

static t_SWITCH sw_name = PB_PRESSURE;
static t_SWITCH_STATE sw_state = PB_RELEASED;

t_SWITCH sw_get_name(void)
{
    return sw_name;
}

t_SWITCH_STATE sw_get_state(void)
{
    return sw_state;
}