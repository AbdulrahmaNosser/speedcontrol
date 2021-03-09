#include <stdio.h>
#include "switch.h"

static t_SWITCH sw_name;
static t_SWITCH_STATE sw_state;
static uint8_t sw_duration;

void SW_Read(void)
{
    FILE * p_file;
    char * sw_name_string[10];
    char * sw_state_string[54];
    char * sw_duration_string[12];

    p_file = fopen("switch.txt", "r");
    fgets(sw_name_string, 10, p_file);
    puts(sw_name_string);

    fclose(p_file);
}

t_SWITCH SW_GetName(void)
{
    return sw_name;
}

t_SWITCH_STATE SW_GetState(void)
{
    return sw_state;
}

uint8_t SW_GetDuration(void)
{
    return sw_duration;
}