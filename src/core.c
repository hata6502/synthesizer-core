// Copyright [2020] <Tomoyuki Hata>

#include <stdio.h>
#include <stdlib.h>

#include "Component.h"
#include "OutPort.h"
#include "port.h"

#define TEST 16

int main() {
  Component components[TEST];

  for (int index = 0; index < TEST; index++) {
    initComponent(&components[index], Mixer);
  }

  OutPort outPort;

  initOutPort(&outPort);

  connectPort(components[0].inPorts[0], &outPort);

  for (int index = 1; index < TEST; index++) {
    connectPort(components[index].inPorts[0], components[index - 1].outPort);
    connectPort(components[index - 1].inPorts[1], components[index].outPort);
  }

  syncComponentCount = 0;

  setOutPortValue(&outPort, 1.0);

  printf("%f\n", components[TEST - 1].outPort->value);

  return EXIT_SUCCESS;
}
