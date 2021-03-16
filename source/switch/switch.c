/**
 * @file switch.c.
 * @brief  This file has the function definitions that retrieve and processes the switches data.
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "switch.h"


static const char * read_file_name = "switch.txt";
static t_SWITCH sw_name;
static t_SWITCH_STATE sw_state;
static uint16_t sw_duration;
static uint8_t priority_flag = 1;
static int8_t end_of_file = NULL;

/**
 * @brief Clears the switch variables.
 * @details This function is called in SW_Read() to clear the switch variables to prepare for the prioritization function SW_Priority() to properly work.
 */
static void SW_Clear(void)
{
    sw_name = -1;
    sw_state = -1;
    sw_duration = 0;
}


/**
 * @brief Sets the priority flag for the switches.
 * @param sw_name_string The name of the currently triggered switch.
 * @param sw_state_string The state of the currently triggered switch.
 * @details This function is called in SW_Read() to set the priority flag to 1. In case of more than 1 switch is triggered at the same time it will report the switch with the highest priority and a valid trigger.
 */
static void SW_Priority(char * sw_name_string, char* sw_state_string)
{
    if (!strcmp(sw_name_string, "p") && !strcmp(sw_name_string, "pressed"))
    {
        priority_flag = 1;
    }
    else if (!strcmp(sw_name_string, "-ve") && sw_name != SW_PRESSURE && !strcmp(sw_name_string, "pre_pressed"))
    {
        priority_flag = 1;
    }
    else if (!strcmp(sw_name_string, "+ve") && sw_name != SW_PRESSURE && sw_name != SW_MINUS && !strcmp(sw_name_string, "pre_pressed"))
    {
        priority_flag = 1;
    }
    else if (sw_name == -1)
    {
        priority_flag = 1;
    }
    
    else
    {
        priority_flag = 0;
    }
}

/**
 * @brief Assigns the read switch data to the switch variables.
 * @param sw_name_string The read switch name.
 * @param sw_state_string The read switch state.
 * @param sw_duration_var The read switch trigger duration.
 * @details This function is called by SW_Read() assign the switch variables with the proper values that the motor can read.
 */
static void SW_Assign_Vars(char * sw_name_string, char * sw_state_string, uint16_t sw_duration_var)
{
    if (priority_flag)
    {   //assigning switch name.
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

        //assigning switch state.
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
        //assgining duration.
        sw_duration = sw_duration_var;
    }
    else
    {
        priority_flag = 1;      //sets priority flag for subsequent use.
    }
}

/**
 * @brief Updates the cursor location for reading the switch file.
 * @param p_file A pointer to the file being read.
 * @return int16_t The cursor location in the file.
 * @details This function is called by SW_Read() to capture the last cursor location to be able to continue reading from the last locatoin. If the file has reached its end it sets the cursor to the begging of the file. In short it makes SW_Read() reentrant.
 */
static int16_t Cursor_Update(FILE * p_file)
{
    int16_t cursor;

    if (fgetc(p_file) == EOF)
    {
        end_of_file = EOF;
        cursor = 0;
    }
    else
    {
        cursor = ftell(p_file) - 1;
    }

    return cursor;
}

void SW_Read(void)
{
    FILE * p_file;
    char * line[22];
    uint16_t sw_order;
    char * sw_name_string[4];
    char * sw_state_string[13];
    uint16_t sw_duration_var;
    static int16_t cursor = 0;
    uint16_t sw_triggering_order;

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

        SW_Priority(sw_name_string, sw_state_string);
        SW_Assign_Vars(sw_name_string, sw_state_string, sw_duration_var);

        //checks if there is another switch clicked simultaneously.
        fscanf(p_file, "%hu ", &sw_triggering_order);       
    } while(sw_triggering_order == sw_order);

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

int8_t SW_FileEnd(void)
{
    return end_of_file;
}
