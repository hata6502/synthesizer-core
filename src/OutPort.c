#include <stddef.h>

#include "OutPort.h"

OutPort *initOutPort(OutPort *outPort) {
  outPort->inPort = NULL;

  return outPort;
}
