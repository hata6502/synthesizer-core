// Copyright [2020] <Tomoyuki Hata>

#include <math.h>
#include <stddef.h>

#include "../Component.h"
#include "SineComponent.h"

void initSineComponent(SineComponent *sineComponent) {
  initComponent(&sineComponent->super, Sine);

  sineComponent->phase = 0.0;
}

void deinitSineComponent(SineComponent *sineComponent) {
  deinitComponent(&sineComponent->super);
}

double syncSineComponent(SineComponent *sineComponent) {
  double deltaTime = getOutPortValue(
    sineComponent->super.inPorts[COMPONENT_DELTA_TIME_IN_PORT]->outPort);

  double frequency = getOutPortValue(
    sineComponent->super.inPorts[SINE_COMPONENT_FREQUENCY_IN_PORT]->outPort);

  double deltaPhase = 2.0*M_PI*deltaTime*frequency;

  sineComponent->phase += isnan(deltaPhase) ? 0.0 : deltaPhase;

  return sin(sineComponent->phase);
}
