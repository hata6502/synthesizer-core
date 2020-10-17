// Copyright [2020] <Tomoyuki Hata>

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "Component.h"
#include "components/MixerComponent.h"
#include "components/SineComponent.h"

#define INFINITE_LOOP_COUNT 65536

#define SYNC_COMPONENT_HANDLERS ((double (* [])(Component *)) { \
  (double (*)(Component *))syncMixerComponent, \
  (double (*)(Component *))syncSineComponent, \
})

int syncComponentCount;

void initComponent(Component *component, ComponentType type) {
  component->type = type;

  for (int index = 0; index < COMPONENT_IN_PORTS_LENGTH; index++) {
    component->inPorts[index] = malloc(sizeof(InPort));

    initInPort(component->inPorts[index], component);
  }

  component->outPort = malloc(sizeof(OutPort));
}

void deinitComponent(Component *component) {
  for (int index = 0; index < COMPONENT_IN_PORTS_LENGTH; index++) {
    deinitInPort(component->inPorts[index]);
    free(component->inPorts[index]);
  }

  deinitOutPort(component->outPort);
  free(component->outPort);
}

void syncComponent(Component *component) {
  syncComponentCount++;

  if (syncComponentCount >= INFINITE_LOOP_COUNT) {
    fprintf(stderr, "syncComponent: Infinite loop detected. \n");
    exit(EXIT_FAILURE);
  }

  setOutPortValue(
    component->outPort,
    SYNC_COMPONENT_HANDLERS[component->type](component));
}
