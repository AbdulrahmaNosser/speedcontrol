/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "../cmock/cmock.h"
#include "Mockswitch.h"

static const char* CMockString_sw_get_name = "sw_get_name";
static const char* CMockString_sw_get_pressed_duration = "sw_get_pressed_duration";
static const char* CMockString_sw_get_state = "sw_get_state";

typedef struct _CMOCK_sw_get_name_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  t_SWITCH ReturnVal;

} CMOCK_sw_get_name_CALL_INSTANCE;

typedef struct _CMOCK_sw_get_state_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  t_SWITCH_STATE ReturnVal;

} CMOCK_sw_get_state_CALL_INSTANCE;

typedef struct _CMOCK_sw_get_pressed_duration_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  uint8_t ReturnVal;

} CMOCK_sw_get_pressed_duration_CALL_INSTANCE;

static struct MockswitchInstance
{
  CMOCK_MEM_INDEX_TYPE sw_get_name_CallInstance;
  CMOCK_MEM_INDEX_TYPE sw_get_state_CallInstance;
  CMOCK_MEM_INDEX_TYPE sw_get_pressed_duration_CallInstance;
} Mock;

extern jmp_buf AbortFrame;

void Mockswitch_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.sw_get_name_CallInstance;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_sw_get_name);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  call_instance = Mock.sw_get_state_CallInstance;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_sw_get_state);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  call_instance = Mock.sw_get_pressed_duration_CallInstance;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_sw_get_pressed_duration);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
}

void Mockswitch_Init(void)
{
  Mockswitch_Destroy();
}

void Mockswitch_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
}

t_SWITCH sw_get_name(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_sw_get_name_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_sw_get_name);
  cmock_call_instance = (CMOCK_sw_get_name_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.sw_get_name_CallInstance);
  Mock.sw_get_name_CallInstance = CMock_Guts_MemNext(Mock.sw_get_name_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void sw_get_name_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, t_SWITCH cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_sw_get_name_CALL_INSTANCE));
  CMOCK_sw_get_name_CALL_INSTANCE* cmock_call_instance = (CMOCK_sw_get_name_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.sw_get_name_CallInstance = CMock_Guts_MemChain(Mock.sw_get_name_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(t_SWITCH[sizeof(cmock_to_return) == sizeof(t_SWITCH) ? 1 : -1])); /* add t_SWITCH to :treat_as_array if this causes an error */
}

t_SWITCH_STATE sw_get_state(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_sw_get_state_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_sw_get_state);
  cmock_call_instance = (CMOCK_sw_get_state_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.sw_get_state_CallInstance);
  Mock.sw_get_state_CallInstance = CMock_Guts_MemNext(Mock.sw_get_state_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void sw_get_state_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, t_SWITCH_STATE cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_sw_get_state_CALL_INSTANCE));
  CMOCK_sw_get_state_CALL_INSTANCE* cmock_call_instance = (CMOCK_sw_get_state_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.sw_get_state_CallInstance = CMock_Guts_MemChain(Mock.sw_get_state_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(t_SWITCH_STATE[sizeof(cmock_to_return) == sizeof(t_SWITCH_STATE) ? 1 : -1])); /* add t_SWITCH_STATE to :treat_as_array if this causes an error */
}

uint8_t sw_get_pressed_duration(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_sw_get_pressed_duration_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_sw_get_pressed_duration);
  cmock_call_instance = (CMOCK_sw_get_pressed_duration_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.sw_get_pressed_duration_CallInstance);
  Mock.sw_get_pressed_duration_CallInstance = CMock_Guts_MemNext(Mock.sw_get_pressed_duration_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void sw_get_pressed_duration_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_sw_get_pressed_duration_CALL_INSTANCE));
  CMOCK_sw_get_pressed_duration_CALL_INSTANCE* cmock_call_instance = (CMOCK_sw_get_pressed_duration_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.sw_get_pressed_duration_CallInstance = CMock_Guts_MemChain(Mock.sw_get_pressed_duration_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

