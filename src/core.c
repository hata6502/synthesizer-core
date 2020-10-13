// Copyright [2020] <Tomoyuki Hata>

#include <stdio.h>
#include <stdlib.h>

#include "Component.h"
#include "OutPort.h"
#include "port.h"

int main() {
  Component component1;
  Component component2;
  OutPort outPort;

  initComponent(&component1, Mixer);
  initComponent(&component2, Mixer);

  initOutPort(&outPort);

  connectPort(component1.inPorts[0], &outPort);

  connectPort(component2.inPorts[0], component1.outPort);
  connectPort(component2.inPorts[1], &outPort);

  setOutPortValue(&outPort, 1.5);

  printf("%f\n", component2.outPort->value);

  return EXIT_SUCCESS;
}
