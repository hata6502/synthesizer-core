// Copyright [2020] <Tomoyuki Hata>

#pragma once

#define COMPONENT_IN_PORTS_LENGTH 16

struct component_t;

typedef enum component_type_t { Mixer } ComponentType;

#include "InPort.h"
#include "OutPort.h"

typedef struct component_t {
  struct in_port_t *inPorts[COMPONENT_IN_PORTS_LENGTH];
  struct out_port_t *outPort;
  ComponentType type;
} Component;

void initComponent(Component *, ComponentType);
void deinitComponent(Component *);
double mixerSynchronizer(struct in_port_t *[COMPONENT_IN_PORTS_LENGTH]);
void syncComponent(Component *);
