#pragma once

struct out_port_t;

#include "InPort.h"

typedef struct out_port_t {
  struct in_port_t *inPort;
  double value;
} OutPort;

OutPort *initOutPort(OutPort *);
