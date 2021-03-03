#ifndef FAKESW_H_INCLUDED
#define FAKESW_H_INCLUDED

/* Include Real Switch module header file to expose Types */
#include "../../source/switch/switch.h"


void       FAKE_SW_init(void);
void       FAKE_SW_destroy(void);


SWITCH_STATE_t  FAKE_SW_getSwState(void);
void       FAKE_SW_setSwState(SWITCH_STATE_t state);

/* You can add whatever you need to test the calling module */

#endif // FAKESW_H_INCLUDED
