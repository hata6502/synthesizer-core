// Copyright [2020] <Tomoyuki Hata>

#include <stdio.h>

#include "Component.h"
#include "OutPort.h"
#include "port.h"

int main() {
  Component component1, component2;
  OutPort outPort;

  initComponent(&component1, Mixer);
  initComponent(&component2, Mixer);

  initOutPort(&outPort);

  connectPort(component1.inPorts[0], &outPort);

  connectPort(component2.inPorts[0], component1.outPort);
  connectPort(component2.inPorts[1], &outPort);

  outPort.value = 1.5;

  syncComponent(outPort.inPort->component);

  printf("%f\n", component2.outPort->value);

  return 0;
}
