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
    for (i = 0; i < 16; i++) {
        for (int j = 0; j < 8; j++) {
            int idx = i * 8 + j;
            random_seed = random_seed * 214013 + 2531011;
            noise_samples[idx] = (delta * (float)((random_seed >> 16) & 32767) - 1.);
        }
    }
}
