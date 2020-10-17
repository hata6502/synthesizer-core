// Copyright [2020] <Tomoyuki Hata>

#pragma once

#define MIXER_COMPONENT_VALUE_IN_PORT 1

struct mixer_component_t;

#include "../Component.h"

typedef struct mixer_component_t {
  Component super;
} MixerComponent;

void initMixerComponent(MixerComponent *);
void deinitMixerComponent(MixerComponent *);
double syncMixerComponent(MixerComponent *);
