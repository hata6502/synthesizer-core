// Copyright [2020] <Tomoyuki Hata>

#include "port.h"

void connectPort(InPort *inPort, OutPort *outPort) {
  // TODO: disconnect prev ports
  inPort->value = &outPort->value;
  outPort->inPort = inPort;
}
