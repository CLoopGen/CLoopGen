#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples;
extern int nb_samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int32_t *indices = samples;
    for (i = 0; i < nb_samples; i++)
        if (samples[indices[i] % nb_samples])
            break;
}
