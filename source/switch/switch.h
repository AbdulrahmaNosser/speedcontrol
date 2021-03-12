/**
 * @file switch.h.
 * @brief This file has the function declerations that retrieve and processes the switches data.
 * @see switch.c for the implementation and the static functions.
 */

#ifndef SWITCH_H
#define SWITCH_H

#include <stdint.h>

/**
 * @brief Enumeration of the switches names.
 * @details SW_PRESSURE is "p" switch, SW_MINUS is "-ve" switch, SW_PLUS is "+ve" switch.
 */
typedef enum
{   
    SW_PRESSURE,    /**< "p" switch. */
    SW_MINUS,       /**< "-ve" switch. */
    SW_PLUS         /**< "+ve" switch. */
}t_SWITCH;

/**
 * @brief Enumeration of the switches possible states.
 */
typedef enum
{
    SW_S_RELEASED,      /**< Released state. */
    SW_S_PRE_PRESSED,   /**< pre pressed state. */
    SW_S_PRESSED,       /**< pressed state. */
    SW_S_PRE_RELEASED   /**< pre released state. */
}t_SWITCH_STATE;

/**
 * @brief Reads the currently triggered switch.
 * @details This function encapsulates the logic of reading, parsing, and prioritizing the triggered switches.
 */
void SW_Read(void);

/**
 * @brief Gets the last read switch name.
 * @return t_SWITCH The last read switch name.
 */
t_SWITCH SW_GetName(void);

/**
 * @brief Gets the last read switch state.
 * @return t_SWITCH_STATE The last read switch state.
 */
t_SWITCH_STATE SW_GetState(void);

/**
 * @brief Gets the last read switch triggering duration.
 * @return uint16_t The last read switch triggering duration.
 */
uint16_t SW_GetDuration(void);

/**
 * @brief The switch file end indication.
 * @return int8_t -1 if the end of file has been reached, 0 otherwise.
 */
int8_t SW_FileEnd(void);

#endif
