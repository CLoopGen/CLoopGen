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
for (i = 0; i < 128; i += 2) {
    random_seed = random_seed * 214013 + 2531011;
    float val1 = (float)((random_seed >> 16) & 32767);
    random_seed = random_seed * 214013 + 2531011;
    float val2 = (float)((random_seed >> 16) & 32767);
    noise_samples[i] = delta * val1 - 1.0f;
    if (i + 1 < 128) {
        noise_samples[i + 1] = delta * val2 - 1.0f;
    }
}
}
