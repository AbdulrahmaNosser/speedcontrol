#include <stdio.h>
#include <string.h>

#include "switch.h"

static t_SWITCH sw_name;
static t_SWITCH_STATE sw_state;
static uint16_t sw_duration;


static void SW_Assign_Vars(char * sw_name_string, char * sw_state_string, uint16_t sw_duration_var)
{
    if (!strcmp(sw_name_string, "p"))
    {
        sw_name = SW_PRESSURE;
        // puts("in P");
    }
    else if (!strcmp(sw_name_string, "-ve"))
    {
        sw_name = SW_MINUS;
        // puts("in minus");
    }
    else if (!strcmp(sw_name_string, "+ve"))
    {
        sw_name = SW_PLUS;
        // puts("in Plus");
    }
    else
    {
        printf("\ninvalid input\n");
    }


    if (!strcmp(sw_state_string, "released"))
    {
        sw_state = SW_S_RELEASED;
        // puts("in released");
    }
    else if (!strcmp(sw_state_string, "pre_pressed"))
    {
        sw_state = SW_S_PRE_PRESSED;
        // puts("in pre relreased");
    }
    else if (!strcmp(sw_state_string, "pressed"))
    {
        sw_state = SW_S_PRESSED;
        // puts("in Pressed");
    }
    else if (!strcmp(sw_state_string, "pre_released"))
    {
        sw_state = SW_S_PRE_RELEASED;
        // puts("in Pre released");
    }
    else
    {
        printf("\ninvalid input\n");
    }

    sw_duration = sw_duration_var;
}

static int16_t Cursor_Update(FILE * p_file)
{
        if (fgetc(p_file) == EOF)
    {
        printf("\n_________________________________________\n");
        printf("Reached the end of file and starting over\n\n");
        return 0;
    }
    else
    {
        return ftell(p_file) - 1;
    }
}
void SW_Read(void)
{
    static const char * read_file_name = "switch.txt";

    FILE * p_file;
    char * line[22];
    uint16_t sw_order;
    char * sw_name_string[4];
    char * sw_state_string[13];
    uint16_t sw_duration_var;
    static int16_t cursor = 0;
    p_file = fopen(read_file_name, "r");

    fseek(p_file, cursor, SEEK_SET);

    // do
    // {
        fgets(line, sizeof(line), p_file);
        sscanf(line, "%hu %s %s %hu", &sw_order, sw_name_string, sw_state_string, &sw_duration_var);
        puts(line); //testing

    // } while();
    

    cursor = Cursor_Update(p_file);

    SW_Assign_Vars(sw_name_string, sw_state_string, sw_duration_var);
    printf("%d %d %d\n", sw_name, sw_state, sw_duration);

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

uint16_t SW_GetDuration(void)
{
    return sw_duration;
}