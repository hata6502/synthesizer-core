// Copyright [2020] <Tomoyuki Hata>

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdlib.h>

#include "OutPort.h"
#include "port.h"
#include "components/MixerComponent.h"

void shouldMixValues();

int main() {
  CU_initialize_registry();

  CU_pSuite mixerComponentSuite = CU_add_suite("MixerComponent", NULL, NULL);
  CU_add_test(mixerComponentSuite, "should mix values", shouldMixValues);

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

  unsigned int numberOfTestsFailed = CU_get_number_of_tests_failed();

  CU_cleanup_registry();

  return numberOfTestsFailed != 0;
}

void shouldMixValues() {
  MixerComponent mixerComponent;
  OutPort outPort1, outPort2;

  initMixerComponent(&mixerComponent);
  initOutPort(&outPort1);
  initOutPort(&outPort2);

  connectPort(mixerComponent.super.inPorts[0], &outPort1);
  connectPort(mixerComponent.super.inPorts[1], &outPort2);

  setOutPortValue(&outPort1, 1.0);
  setOutPortValue(&outPort2, 1.5);

  CU_ASSERT(getOutPortValue(mixerComponent.super.outPort) == 2.5);

  deinitMixerComponent(&mixerComponent);
  deinitOutPort(&outPort1);
  deinitOutPort(&outPort2);
}
