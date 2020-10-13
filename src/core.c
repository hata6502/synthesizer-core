// Copyright [2020] <Tomoyuki Hata>

#define COMPONENT_LENGTH 8192

#include <stdio.h>
#include <stdlib.h>

#include "Component.h"
#include "OutPort.h"
#include "port.h"

int main() {
  Component components[COMPONENT_LENGTH];

  for (int index = 0; index < COMPONENT_LENGTH; index++) {
    initComponent(&components[index], Mixer);
  }

  OutPort outPort;

  initOutPort(&outPort);

  connectPort(components[0].inPorts[0], &outPort);
  connectPort(components[0].inPorts[1], &outPort);

  for (int index = 1; index < COMPONENT_LENGTH; index++) {
    connectPort(components[index].inPorts[0], components[index - 1].outPort);
    connectPort(components[index].inPorts[1], components[index - 1].outPort);
  }

  syncComponentCount = 0;

  setOutPortValue(&outPort, 1.0);

  printf("%f\n", components[COMPONENT_LENGTH - 1].outPort->value);

  for (int index = 0; index < COMPONENT_LENGTH; index++) {
    deinitComponent(&components[index]);
  }

  return EXIT_SUCCESS;
}
