#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples_l;
extern int32_t *samples_r;
extern int i;
extern int nb_samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < nb_samples; i += 2) {
        samples_r[i-1] += ((samples_l[i-1] - samples_r[i-1]) >> 1);
        samples_r[i]   += ((samples_l[i]   - samples_r[i])   >> 1);
    }
    if (i == nb_samples) {
        samples_r[i-1] += ((samples_l[i-1] - samples_r[i-1]) >> 1);
    }
}
