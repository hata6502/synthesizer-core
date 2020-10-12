// Copyright [2020] <Tomoyuki Hata>

#pragma once

#define OUT_PORT_IN_PORTS_LENGTH 16

struct out_port_t;

#include "InPort.h"

typedef struct out_port_t {
  struct in_port_t *inPorts[OUT_PORT_IN_PORTS_LENGTH];
  double value;
} OutPort;

void initOutPort(OutPort *);
void setOutPortValue(OutPort *, double);
