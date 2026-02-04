#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float tmp[22];

float *features;

void init_vars() {
    size_t total_size = 1 << 20; // 1MB of data
    features = (float*)aligned_alloc(32, total_size);
    if (!features) {
        exit(1);
    }
    
    for (size_t i = 0; i < total_size / sizeof(float); i++) {
        features[i] = 0.0f;
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}