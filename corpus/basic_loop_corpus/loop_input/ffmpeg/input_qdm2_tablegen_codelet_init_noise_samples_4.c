#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float noise_samples[128];
int i;
unsigned int random_seed = 12345;
float delta = 0.0001f;

void init_vars() {
    // No additional initialization needed beyond static initializers
    // All required variables are already defined and initialized at file scope
}