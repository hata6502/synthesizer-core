// Copyright [2020] <Tomoyuki Hata>

#pragma once

enum component_type_t;
struct component_t;

#include "InPort.h"
#include "OutPort.h"

#define COMPONENT_IN_PORTS_LENGTH 16

typedef enum component_type_t { Mixer } ComponentType;

typedef struct component_t {
  struct in_port_t *inPorts[COMPONENT_IN_PORTS_LENGTH + 1];
  struct out_port_t *outPort;
  ComponentType type;
} Component;

void initComponent(Component *, ComponentType);
void deinitComponent(Component *);
double mixerSynchronizer(struct in_port_t *[COMPONENT_IN_PORTS_LENGTH]);
void syncComponent(Component *);
