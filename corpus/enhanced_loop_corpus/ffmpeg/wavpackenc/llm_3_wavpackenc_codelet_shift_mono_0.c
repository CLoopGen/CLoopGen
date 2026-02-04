#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples;
extern int nb_samples;
extern int shift;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t *indices = (int32_t*)malloc(nb_samples * sizeof(int32_t));
    for (int j = 0; j < nb_samples; j++) {
        indices[j] = nb_samples - 1 - j; // reverse access pattern
    }
    for (i = 0; i < nb_samples; i++) {
        samples[indices[i]] >>= shift;
    }
    free(indices);
}
