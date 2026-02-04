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
    int j;
    for (i = 0; i < nb_samples; i += 2) {
        if (i + 1 < nb_samples) {
            samples[i] >>= shift;
            samples[i + 1] >>= shift;
        } else {
            samples[i] >>= shift;
        }
    }
}
