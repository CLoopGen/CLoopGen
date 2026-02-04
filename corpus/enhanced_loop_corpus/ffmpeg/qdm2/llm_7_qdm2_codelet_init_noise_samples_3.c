#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float noise_samples[128];
extern int i;
extern unsigned int random_seed;
extern float delta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int local_seed = random_seed;
    for (i = 0; i < 128; i++) {
        local_seed = local_seed * 214013 + 2531011;
        noise_samples[i] = delta * (float)((local_seed >> 16) & 32767) - 1.0f;
    }
    random_seed = local_seed;
}
