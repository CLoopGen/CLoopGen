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
    for (i = 0; i < 64; i += 2) {
        random_seed = random_seed * 214013 + 2531011;
        noise_samples[i] = (delta * (float)((random_seed >> 16) & 32767) - 1.);
        random_seed = random_seed * 214013 + 2531011;
        noise_samples[i+1] = (delta * (float)((random_seed >> 16) & 32767) - 1.);
    }
}
