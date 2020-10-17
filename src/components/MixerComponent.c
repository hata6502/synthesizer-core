// Copyright [2020] <Tomoyuki Hata>

#include <stddef.h>

#include "../Component.h"
#include "MixerComponent.h"

void initMixerComponent(MixerComponent *mixerComponent) {
  initComponent(&mixerComponent->super, Mixer);
}

void deinitMixerComponent(MixerComponent *mixerComponent) {
  deinitComponent(&mixerComponent->super);
}

double syncMixerComponent(MixerComponent *mixerComponent) {
  double sum = 0.0;

  for (int index = MIXER_COMPONENT_VALUE_IN_PORT;
    index < COMPONENT_IN_PORTS_LENGTH;
    index++) {
    OutPort *outPort = mixerComponent->super.inPorts[index]->outPort;

    if (outPort == NULL) {
      continue;
    }

    sum += getOutPortValue(outPort);
  }

  return sum;
}
