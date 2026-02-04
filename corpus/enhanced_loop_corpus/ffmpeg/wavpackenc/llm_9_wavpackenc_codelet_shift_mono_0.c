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
    int factor = (shift > 0) ? shift : 1;
    for (i = 0; i < nb_samples; i++) {
        samples[i] >>= shift;
        samples[i] += i * factor;
        samples[i] = (samples[i] < 0) ? -samples[i] : samples[i];
    }
}
