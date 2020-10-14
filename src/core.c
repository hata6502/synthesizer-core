// Copyright [2020] <Tomoyuki Hata>

#define COMPONENT_LENGTH 4096

#include <stdio.h>
#include <stdlib.h>

#include "OutPort.h"
#include "port.h"
#include "components/MixerComponent.h"

int main() {
  MixerComponent components[COMPONENT_LENGTH];

  for (int index = 0; index < COMPONENT_LENGTH; index++) {
    initMixerComponent(&components[index]);
  }

  OutPort outPort;

  initOutPort(&outPort);

  connectPort(components[0].super.inPorts[0], &outPort);
  connectPort(components[0].super.inPorts[1], &outPort);

  for (int index = 1; index < COMPONENT_LENGTH; index++) {
    connectPort(
      components[index].super.inPorts[0],
      components[index - 1].super.outPort);
    connectPort(
      components[index].super.inPorts[1],
      components[index - 1].super.outPort);
  }

  syncComponentCount = 0;

  setOutPortValue(&outPort, 1.0);

  printf("%f\n", components[COMPONENT_LENGTH - 1].super.outPort->value);

  for (int index = 0; index < COMPONENT_LENGTH; index++) {
    deinitMixerComponent(&components[index]);
  }

  return EXIT_SUCCESS;
}
