// Copyright [2020] <Tomoyuki Hata>

#include <stddef.h>

#include "Component.h"
#include "OutPort.h"

void initOutPort(OutPort *outPort) {
  int index;

  for (index = 0; index < OUT_PORT_IN_PORTS_LENGTH; index++) {
    outPort->inPorts[index] = NULL;
  }
}

void setOutPortValue(OutPort *outPort, double value) {
  int index;

  outPort->value = value;

  for (index = 0; index < OUT_PORT_IN_PORTS_LENGTH; index++) {
    if (outPort->inPorts[index] == NULL) {
      continue;
    }

    syncComponent(outPort->inPorts[index]->component);
  }
}
