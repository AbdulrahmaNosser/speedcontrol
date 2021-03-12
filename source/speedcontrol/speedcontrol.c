/**
 * \defgroup speed_control Speed control documentation
 * @{
 */
/**
 * @file speedcontrol.c.
 * @brief This file has the function definitions that handle the motor speed.
 */

#include <stdint.h>
#include <stdio.h>

#include "speedcontrol.h"
#include "../switch/switch.h"

/**
 * @brief Stores the current motor speed.
 *
 */
static uint8_t motor_speed = MID_SPEED;

/**
 * @brief Holds the file name for writing the motor speed.
 *
 */
static const char * write_file_name = "motor.txt";

/**
 * @brief The logic of the **p switch.**
 * @details This function decides whether the motor speed should decrease or not if the **Pressure switch** is pressed.
 * It is called by MotorUpdate() to handle the **p switch** logic.
 * @param sw_state to indicate the pressing state of the switch.
 * @param sw_duration to indicate the duration of the press.
 */
static void Logic_SW_Pressure(t_SWITCH_STATE sw_state, uint8_t sw_duration)
{
    if (sw_state == SW_S_PRESSED)
    {
        if (sw_duration >= 30)
        {
            if (motor_speed == MAX_SPEED)
            {
                motor_speed = MID_SPEED;
            }
            else if (motor_speed == MID_SPEED)
            {
                motor_speed = MIN_SPEED;
            }
            else{}
        }
        else{}
    }
    else{}
}

/**
 * @brief The logic of the **-ve switch.**
 * @details This function decides whether the motor speed should decrease or not if the **-ve switch** is pre pressed.
 * It is called by MotorUpdate() to handle the **-ve switch** logic.
 * @param sw_state to indicate the pressing state of the switch.
 */
static void Logic_SW_Minus(t_SWITCH_STATE sw_state)
{
    if (sw_state == SW_S_PRE_PRESSED)
    {
        if (motor_speed == MAX_SPEED)
        {
            motor_speed = MID_SPEED;
        }
        else if (motor_speed == MID_SPEED)
        {
            motor_speed = MIN_SPEED;
        }
        else{}
    }
    else{}
}

/**
 * @brief The logic of the **+ve switch.**
 * @details This function decides whether the motor speed should increase or not if the **+ve switch** is pre pressed.
 * It is called by MotorUpdate() to handle the **+ve switch** logic.
 * @param sw_state to indicate the pressing state of the switch.
 */
static void Logic_SW_Plus(t_SWITCH_STATE sw_state)
{
    if (sw_state == SW_S_PRE_PRESSED)
    {
        if (motor_speed == MID_SPEED)
        {
            motor_speed = MAX_SPEED;
        }
        else if (motor_speed == MIN_SPEED)
        {
            motor_speed = MID_SPEED;
        }
        else{}
    }
    else{}
}

/**
 * @brief Prints the motor speed in a file.
 * @details This function is used by the MotorUpdate() function to print the current speed of the motor in a .txt file.
 */
static void MotorPrint(void)
{
    char * motor_speed_out[5];
    static cursor = 0;
    FILE * p_file;

    p_file = fopen(write_file_name, "w");

    fseek(p_file, cursor, SEEK_SET);
    fprintf(p_file, "%d\n", motor_speed);
    cursor = ftell(p_file);
}

void MotorInit (void)
{
    motor_speed = MID_SPEED;
}

void MotorSet (uint8_t speed)
{
    if (speed == MIN_SPEED || speed == MID_SPEED || speed == MAX_SPEED)
    {
        motor_speed = speed;
    }
    else
    {

    }
}

uint8_t MotorGet (void)
{
    return motor_speed;
}

void MotorUpdate (t_SWITCH sw_name, t_SWITCH_STATE sw_state, uint16_t sw_duration)
{
    switch (sw_name)
    {
    case SW_PRESSURE:
        Logic_SW_Pressure(sw_state, sw_duration);
        break;

    case SW_MINUS:
        Logic_SW_Minus(sw_state);
        break;

    case SW_PLUS:
        Logic_SW_Plus(sw_state);
        break;

    default:
        break;
    }

    MotorPrint();
}
/**@}*/
