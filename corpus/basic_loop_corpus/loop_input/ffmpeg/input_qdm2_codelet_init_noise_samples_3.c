#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float noise_samples[128];
int i;
unsigned int random_seed;
float delta;

void init_vars() {
    random_seed = 12345u;
    delta = 0.00003051850947599719f; // Approximately 1.0 / 32767.0
}