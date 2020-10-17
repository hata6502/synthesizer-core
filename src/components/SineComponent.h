// Copyright [2020] <Tomoyuki Hata>

#pragma once

#define SINE_COMPONENT_FREQUENCY_IN_PORT 1

struct sine_component_t;

#include "../Component.h"

typedef struct sine_component_t {
  Component super;
  double phase;
} SineComponent;

void initSineComponent(SineComponent *);
void deinitSineComponent(SineComponent *);
double syncSineComponent(SineComponent *);
