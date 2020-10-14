// Copyright [2020] <Tomoyuki Hata>

#include <stddef.h>

#include "../Component.h"
#include "MixerComponent.h"

void initMixerComponent(MixerComponent *component) {
  initComponent((Component *)component, Mixer);
}

void deinitMixerComponent(MixerComponent *component) {
  deinitComponent((Component *)component);
}

double syncMixerComponent(MixerComponent *component) {
  double sum = 0.0;

  for (int index = 0; index < COMPONENT_IN_PORTS_LENGTH; index++) {
    OutPort *outPort = component->super.inPorts[index]->outPort;

    if (outPort == NULL) {
      continue;
    }

    sum += outPort->value;
  }

  return sum;
}
