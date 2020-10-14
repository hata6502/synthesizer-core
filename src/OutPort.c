// Copyright [2020] <Tomoyuki Hata>

#include <math.h>
#include <stddef.h>

#include "Component.h"
#include "OutPort.h"

void initOutPort(OutPort *outPort) {
  for (int index = 0; index < OUT_PORT_IN_PORTS_LENGTH; index++) {
    outPort->inPorts[index] = NULL;
  }

  outPort->_value = NAN;
}

void deinitOutPort(OutPort *outPort) {}

double getOutPortValue(OutPort *outPort) {
  return outPort->_value;
}

void setOutPortValue(OutPort *outPort, double value) {
  if (outPort->_value == value) {
    return;
  }

  outPort->_value = value;

  for (int index = 0; index < OUT_PORT_IN_PORTS_LENGTH; index++) {
    if (outPort->inPorts[index] == NULL) {
      continue;
    }

    syncComponent(outPort->inPorts[index]->component);
  }
}
