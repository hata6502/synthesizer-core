// Copyright [2020] <Tomoyuki Hata>

#include <stddef.h>

#include "InPort.h"

void initInPort(InPort *inPort, Component *component) {
  inPort->component = component;
  inPort->outPort = NULL;
}
