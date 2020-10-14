// Copyright [2020] <Tomoyuki Hata>

#pragma once

struct mixer_component_t;

#include "../Component.h"

typedef struct mixer_component_t {
  Component super;
} MixerComponent;

void initMixerComponent(MixerComponent *component);
void deinitMixerComponent(MixerComponent *component);
double syncMixerComponent(MixerComponent *component);
