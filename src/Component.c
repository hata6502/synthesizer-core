// Copyright [2020] <Tomoyuki Hata>

#include <stddef.h>
#include <stdlib.h>

#include "Component.h"

void initComponent(Component *component, ComponentType type) {
  int index;

  component->type = type;

  for (index = 0; index < COMPONENT_IN_PORTS_LENGTH; index++) {
    component->inPorts[index] = (InPort *)malloc(sizeof(InPort));

    initInPort(component->inPorts[index], component);
  }

  //component->inPorts[COMPONENT_IN_PORTS_LENGTH] = NULL;

  component->outPort = (OutPort *)malloc(sizeof(OutPort));
}

void deinitComponent(Component *component) {
  int index;

  for (index = 0; index < COMPONENT_IN_PORTS_LENGTH; index++) {
    free(component->inPorts[index]);
  }

  free(component->outPort);
}

double mixerSynchronizer(InPort *inPorts[COMPONENT_IN_PORTS_LENGTH]) {
  int index;
  double sum = 0.0;

  for (index = 0; index < COMPONENT_IN_PORTS_LENGTH; index++) {
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
  component->outPort->value = synchronizer[component->type](component->inPorts);
}
