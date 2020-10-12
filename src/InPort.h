#pragma once

struct in_port_t;

#include "Component.h"

typedef struct in_port_t {
  struct component_t *component;
  double *value;
} InPort;

InPort *initInPort(InPort *, struct component_t *);
