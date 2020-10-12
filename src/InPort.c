#include <stddef.h>

#include "InPort.h"

InPort *initInPort(InPort *inPort, Component *component) {
  inPort->component = component;
  inPort->value = NULL;

  return inPort;
}
