#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float noise_table[4116];
extern int i;
extern uint64_t random_seed;
extern float delta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[4096];
    for (int j = 0; j < 4096; j++) {
        indices[j] = (j * 7) % 4096; // Stride of 7 modulo size to cover all indices
    }
    for (i = 0; i < 4096; i++) {
        random_seed = random_seed * 214013 + 2531011;
        int idx = indices[i];
        noise_table[idx] = (delta * (float)(((int32_t)random_seed >> 16) & 32767) - 1.) * 1.3;
    }
}
