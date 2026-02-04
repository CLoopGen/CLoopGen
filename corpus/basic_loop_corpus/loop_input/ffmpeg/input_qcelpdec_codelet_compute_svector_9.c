#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *gain;
float *cdn_vector;
int i;
int j;
uint16_t cbseed;
float tmp_gain;

void init_vars() {
    gain = (float*)aligned_alloc(32, 8 * sizeof(float));
    cdn_vector = (float*)aligned_alloc(32, 8 * 20 * sizeof(float));
    if (!gain || !cdn_vector) {
        exit(1);
    }
    for (int idx = 0; idx < 8; idx++) {
        gain[idx] = (float)(idx + 1) * 0.5f;
    }
    cbseed = 31415U;
}

extern void loop();

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}