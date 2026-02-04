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
    for (i = 0; i < 128; i++) {
        random_seed = random_seed * 214013 + 2531011;
        if ((random_seed & 0x8000) == 0) {
            noise_samples[i] = delta * (float)((random_seed >> 16) & 32767) - 1.;
        } else {
            noise_samples[i] = 0.0f;
        }
    }
}
