#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "switch.h"


static const char * read_file_name = "switch.txt";
static t_SWITCH sw_name;
static t_SWITCH_STATE sw_state;
static uint16_t sw_duration;
static uint8_t priority_flag = 1;


static void SW_Clear(void)
{
    sw_name = -1;
    sw_state = -1;
    sw_duration = 0;
}

static void SW_Priority(char * sw_name_string)
{
    if (!strcmp(sw_name_string, "p"))
    {
        priority_flag = 1;
    }
    else if (!strcmp(sw_name_string, "-ve") && sw_name != SW_PRESSURE)
    {
        priority_flag = 1;
    }
    else if (!strcmp(sw_name_string, "+ve") && sw_name != SW_PRESSURE && sw_name != SW_MINUS)
    {
        priority_flag = 1;
    }
    else
    {
        priority_flag = 0;
    }
}

static void SW_Assign_Vars(char * sw_name_string, char * sw_state_string, uint16_t sw_duration_var)
{
    if (priority_flag)
    {
        if (!strcmp(sw_name_string, "p"))
        {
            sw_name = SW_PRESSURE;
        }
        else if (!strcmp(sw_name_string, "-ve"))
        {
            sw_name = SW_MINUS;
        }
        else if (!strcmp(sw_name_string, "+ve"))
        {
            sw_name = SW_PLUS;
        }
        else
        {
            printf("\ninvalid input\n");
        }


        if (!strcmp(sw_state_string, "released"))
        {
            sw_state = SW_S_RELEASED;
        }
        else if (!strcmp(sw_state_string, "pre_pressed"))
        {
            sw_state = SW_S_PRE_PRESSED;
        }
        else if (!strcmp(sw_state_string, "pressed"))
        {
            sw_state = SW_S_PRESSED;
        }
        else if (!strcmp(sw_state_string, "pre_released"))
        {
            sw_state = SW_S_PRE_RELEASED;
        }
        else
        {
            printf("\ninvalid input\n");
        }

        sw_duration = sw_duration_var;
    }
    else
    {
        priority_flag = 1;
    }
}

static int16_t Cursor_Update(FILE * p_file)
{
    if (fgetc(p_file) == EOF)
    {
        printf("\n__________________________________________________________\n");
        printf("Reached the end of file and starting over in the next read\n\n");
        return 0;
    }
    else
    {
        return ftell(p_file) - 1;
    }
}

void SW_Read(void)
{
    FILE * p_file;
    char * line[22];
    char * line_2[22];
    uint16_t sw_order;
    char * sw_name_string[4];
    char * sw_state_string[13];
    uint16_t sw_duration_var;
    static int16_t cursor = 0;
    uint16_t sw_order_next;

    p_file = fopen(read_file_name, "r");
    if (p_file == NULL)
    {
        printf("error: %s\n", strerror(errno));
        return;
    }
    

    SW_Clear();

    do
    {
        fseek(p_file, cursor, SEEK_SET);

        fgets(line, sizeof(line), p_file);
        sscanf(line, "%hu %s %s %hu", &sw_order, sw_name_string, sw_state_string, &sw_duration_var);

        cursor = Cursor_Update(p_file);
        fseek(p_file, cursor, SEEK_SET);

        SW_Priority(sw_name_string);
        SW_Assign_Vars(sw_name_string, sw_state_string, sw_duration_var);

        fscanf(p_file, "%hu ", &sw_order_next);
    } while(sw_order_next == sw_order);

    printf("\n final: %d %d %d\n", sw_name, sw_state, sw_duration);

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