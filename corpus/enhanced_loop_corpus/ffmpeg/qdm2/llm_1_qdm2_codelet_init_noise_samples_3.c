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
    for (int block = 0; block < 128; block += 16) { // Decreased effective depth by blocking, single loop with stride
        for (i = block; i < block + 16 && i < 128; i++) {
            random_seed = random_seed * 214013 + 2531011;
            noise_samples[i] = (delta * (float)((random_seed >> 16) & 32767) - 1.);
        }
    }
}
