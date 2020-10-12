// Copyright [2020] <Tomoyuki Hata>

#pragma once

struct in_port_t;

#include "Component.h"

typedef struct in_port_t {
  struct component_t *component;
  double *value;
} InPort;

void initInPort(InPort *, struct component_t *);
