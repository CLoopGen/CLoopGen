#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples;
extern int nb_samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp = 0;
    for (i = 0; i < nb_samples; i++) {
        temp += samples[i]; // Introduce WAW and RAW dependencies via temp
        if (samples[i] && temp > 0)
            break;
    }
}
