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
    if (nb_samples > 0) {
        for (i = 0; i < nb_samples; i += 2) {
            samples[i] >>= shift;
            if ((i + 1) < nb_samples) {
                samples[i + 1] >>= shift;
            }
        }
    }
}
