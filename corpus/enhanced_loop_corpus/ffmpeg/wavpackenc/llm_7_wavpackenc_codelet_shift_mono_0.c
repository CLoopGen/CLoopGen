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
    if (shift > 0 && nb_samples > 1) {
        samples[0] >>= shift;
        for (i = 1; i < nb_samples; i++) {
            samples[i] = (samples[i] + samples[i-1]) >> shift;
        }
    } else {
        for (i = 0; i < nb_samples; i++) {
            samples[i] >>= shift;
        }
    }
}
