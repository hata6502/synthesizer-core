// Copyright [2020] <Tomoyuki Hata>

#include <math.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include "OutPort.h"
#include "port.h"
#include "components/MixerComponent.h"
#include "components/SineComponent.h"

void shouldGenerateSineWave();
void shouldMixValues();

int main() {
  CU_initialize_registry();

  CU_pSuite mixerComponentSuite = CU_add_suite("MixerComponent", NULL, NULL);
  CU_add_test(mixerComponentSuite, "should mix values", shouldMixValues);

  CU_pSuite sineComponentSuite = CU_add_suite("SineComponent", NULL, NULL);

  CU_add_test(sineComponentSuite,
    "should generate sine wave",
    shouldGenerateSineWave);

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

  unsigned int numberOfTestsFailed = CU_get_number_of_tests_failed();

  CU_cleanup_registry();

  return numberOfTestsFailed != 0;
}

void shouldGenerateSineWave() {
  OutPort deltaTimeOutPort;
  OutPort frequencyOutPort;
  SineComponent sineComponent;

  initOutPort(&deltaTimeOutPort);
  initOutPort(&frequencyOutPort);
  initSineComponent(&sineComponent);

  connectPort(sineComponent.super.inPorts[COMPONENT_DELTA_TIME_IN_PORT],
  &deltaTimeOutPort);

  connectPort(sineComponent.super.inPorts[SINE_COMPONENT_FREQUENCY_IN_PORT],
  &frequencyOutPort);

  setOutPortValue(&frequencyOutPort, 1.5);

  for (int index = 0; index < 12; index++) {
    double sineWave[] = {
      0.923880,
      0.707107,
      -0.382683,
      -1.000000,
      -0.382683,
      0.707107,
      0.923880,
      0.000000,
      -0.923880,
      -0.707107,
      0.382683,
      1.000000,
    };

    setOutPortValue(&deltaTimeOutPort, 0.125);
    setOutPortValue(&deltaTimeOutPort, 0.0);

    CU_ASSERT(
      fabs(
        getOutPortValue(sineComponent.super.outPort)
        - sineWave[index]) < 0.01);
  }

  deinitOutPort(&deltaTimeOutPort);
  deinitOutPort(&frequencyOutPort);
  deinitSineComponent(&sineComponent);
}

void shouldMixValues() {
  MixerComponent mixerComponent;
  OutPort outPort1;
  OutPort outPort2;

  initMixerComponent(&mixerComponent);
  initOutPort(&outPort1);
  initOutPort(&outPort2);

  connectPort(
    mixerComponent.super.inPorts[MIXER_COMPONENT_VALUE_IN_PORT],
    &outPort1);

  connectPort(
    mixerComponent.super.inPorts[MIXER_COMPONENT_VALUE_IN_PORT + 1],
    &outPort2);

  setOutPortValue(&outPort1, 1.0);
  setOutPortValue(&outPort2, 1.5);

  CU_ASSERT(getOutPortValue(mixerComponent.super.outPort) == 2.5);

  deinitMixerComponent(&mixerComponent);
  deinitOutPort(&outPort1);
  deinitOutPort(&outPort2);
}
