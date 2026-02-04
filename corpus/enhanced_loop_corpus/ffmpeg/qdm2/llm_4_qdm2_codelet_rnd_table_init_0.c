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
for (i = 0; i < 4096; i++) {
    if (i % 2 == 0) {
        random_seed = random_seed * 214013 + 2531011;
    } else {
        random_seed = random_seed * 1103515245 + 12345;
    }
    noise_table[i] = (delta * (float)(((int32_t)random_seed >> 16) & 32767) - 1.) * 1.3;
}
}
