// Copyright [2020] <Tomoyuki Hata>

#define INFINITE_LOOP_COUNT 65536

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "Component.h"
#include "components/MixerComponent.h"

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

void syncComponent(Component *component) {
  syncComponentCount++;

  if (syncComponentCount >= INFINITE_LOOP_COUNT) {
    fprintf(stderr, "syncComponent: Infinite loop detected. \n");
    exit(EXIT_FAILURE);
  }

  double (* handlers[])(Component *) = {
    (double (*)(Component *))syncMixerComponent
  };

  setOutPortValue(
    component->outPort,
    handlers[component->type](component));
}
