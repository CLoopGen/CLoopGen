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
    uint64_t temp_seed = random_seed;
    float prev_value = 0.0f;
    for (i = 0; i < 4096; i++) {
        temp_seed = temp_seed * 214013 + 2531011;
        int32_t shifted = (int32_t)(temp_seed >> 16) & 32767;
        float current = (delta * (float)shifted - 1.) * 1.3;
        noise_table[i] = current + prev_value; // Introduce RAW dependency: each write depends on prior computed value
        prev_value = current; // Create loop-carried dependency (RAW)
    }
    random_seed = temp_seed;
}
