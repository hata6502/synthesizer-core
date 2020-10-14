// Copyright [2020] <Tomoyuki Hata>

#pragma once

struct in_port_t;

#include "Component.h"
#include "OutPort.h"

typedef struct in_port_t {
  struct component_t *component;
  struct out_port_t *outPort;
} InPort;

void initInPort(InPort *, struct component_t *);
void deinitInPort(InPort *);
