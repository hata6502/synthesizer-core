// Copyright [2020] <Tomoyuki Hata>

#define INFINITE_LOOP_COUNT 65536

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "Component.h"

int syncComponentCount;

void initComponent(Component *component, ComponentType type) {
  component->type = type;

  for (int index = 0; index < COMPONENT_IN_PORTS_LENGTH; index++) {
    component->inPorts[index] = (InPort *)malloc(sizeof(InPort));

    initInPort(component->inPorts[index], component);
  }

  component->outPort = (OutPort *)malloc(sizeof(OutPort));
}

void deinitComponent(Component *component) {
  for (int index = 0; index < COMPONENT_IN_PORTS_LENGTH; index++) {
    free(component->inPorts[index]);
  }

  free(component->outPort);
}

double mixerSynchronizer(InPort *inPorts[COMPONENT_IN_PORTS_LENGTH]) {
  double sum = 0.0;

  for (int index = 0; index < COMPONENT_IN_PORTS_LENGTH; index++) {
    OutPort *outPort = inPorts[index]->outPort;

    if (outPort == NULL) {
      continue;
    }

    sum += outPort->value;
  }

  return sum;
}

double (* synchronizer[])(InPort *[COMPONENT_IN_PORTS_LENGTH]) = {
  mixerSynchronizer
};

void syncComponent(Component *component) {
  syncComponentCount++;

  if (syncComponentCount >= INFINITE_LOOP_COUNT) {
    fprintf(stderr, "syncComponent: Infinite loop detected. \n");
    exit(EXIT_FAILURE);
  }

  setOutPortValue(
    component->outPort,
    synchronizer[component->type](component->inPorts));
}
