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
    float scale1, scale2, offset;
    for (i = 0; i < 4096; i += 2) {
        random_seed = random_seed * 214013 + 2531011;
        scale1 = (float)(((int32_t)random_seed >> 16) & 32767);
        random_seed = random_seed * 214013 + 2531011;
        scale2 = (float)(((int32_t)random_seed >> 16) & 32767);
        offset = -1.0f;

        noise_table[i]     = (delta * scale1 + offset) * 1.3f;
        noise_table[i + 1]   = (delta * scale2 + offset) * 1.3f;
    }
}
