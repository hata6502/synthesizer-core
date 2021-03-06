// Copyright [2020] <Tomoyuki Hata>

#include <stdio.h>
#include <stdlib.h>

#include "OutPort.h"
#include "port.h"

void connectPort(InPort *inPort, OutPort *outPort) {
  disconnectPort(inPort);

  inPort->outPort = outPort;

  int index;

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

void disconnectPort(InPort *inPort) {
  OutPort *outPort = inPort->outPort;

  if (outPort == NULL) {
    return;
  }

  int index;

  for (index = 0; index < OUT_PORT_IN_PORTS_LENGTH; index++) {
    if (outPort->inPorts[index] != inPort) {
      continue;
    }

    outPort->inPorts[index] = NULL;

    break;
  }

  if (index >= OUT_PORT_IN_PORTS_LENGTH) {
    fprintf(stderr, "disconnectPort: InPort is not found. \n");
    exit(EXIT_FAILURE);
  }

  inPort->outPort = NULL;
}
