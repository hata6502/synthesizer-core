// Copyright [2020] <Tomoyuki Hata>

#include "Component.h"
#include "OutPort.h"
#include "port.h"

double simulate() {
  Component component1, component2;
  OutPort outPort;

  // Define components
  initComponent(&component1, Mixer);
  initComponent(&component2, Mixer);

  initOutPort(&outPort);

  // Connect components
  connectPort(&component1.inPorts[0], &outPort);

  connectPort(&component2.inPorts[0], &component1.outPort);
  connectPort(&component2.inPorts[1], &outPort);

  // Set input
  outPort.value = 1.5;

  // Simulate
  syncComponent(outPort.inPort->component);
  syncComponent(outPort.inPort->component->outPort.inPort->component);

  return component2.outPort.value;
}
