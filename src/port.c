// Copyright [2020] <Tomoyuki Hata>

#include <stdio.h>
#include <stdlib.h>

#include "OutPort.h"
#include "port.h"

void connectPort(InPort *inPort, OutPort *outPort) {
  int index;

  // TODO: disconnect prev ports
  inPort->value = &outPort->value;

  for (index = 0; index < OUT_PORT_IN_PORTS_LENGTH; index++) {
    if (outPort->inPorts[index] != NULL) {
      continue;
    }

    outPort->inPorts[index] = inPort;

    break;
  }

  if (index >= OUT_PORT_IN_PORTS_LENGTH) {
    fprintf(stderr, "connectPort: InPort is full. \n");
    exit(EXIT_FAILURE);
  }
}
