#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples;
extern int nb_samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_index = -1;
    for (i = 0; i < nb_samples; i++) {
        if (prev_index != -1 && samples[i] != samples[prev_index]) // Introduce loop-carried RAW dependency
            samples[prev_index] = samples[i]; // WAR and WAW dependency introduced
        if (samples[i])
            break;
        prev_index = i;
    }
}
