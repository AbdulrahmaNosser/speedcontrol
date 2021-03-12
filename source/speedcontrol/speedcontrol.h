/**
 * @file speedcontrol.h.
 * @brief This file has the function declerations that handle the motor speed.
 * @see speedcontrol.c for the implementation and the static functions.
 */

#ifndef SPEEDCONTROL_H
#define SPEEDCONTROL_H

#include <stdint.h>

#include "../switch/switch.h"


#define MIN_SPEED 140
#define MID_SPEED 90
#define MAX_SPEED 10

/**
 * @brief Sets the initial speed.
 * @details Initiates the motor to its default speed **medium speed**.
 */
void MotorInit (void);

/**
 * @brief Sets the motor into a custom speed.
 * @param speed The desired speed to be set.
 */
void MotorSet (uint8_t speed);

/**
 * @brief Gets the motor speed.
 * @return The current speed of the motor.
 */
uint8_t MotorGet (void); 

/**
 * @brief Updates the motor speed.
 * @details This function encapsulates all the decision making process of updating the motor speed.
 * It calls multiple static functions to complete its functionality. Logic_SW_Pressure(), Logic_SW_Minus(), Logic_SW_Plus(), MotorPrint().
 * @param sw_name The switch name pressed.
 * @param sw_state The state of the press.
 * @param sw_duration The duration of the press.
 */
void MotorUpdate (t_SWITCH sw_name, t_SWITCH_STATE sw_state, uint16_t sw_duration);

#endif
