#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples_l;
extern int32_t *samples_r;
extern int nb_samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < nb_samples; i += step) {
        if (samples_l[i] || samples_r[i])
            break;
        if (i + 1 < nb_samples && (samples_l[i + 1] || samples_r[i + 1])) {
            i++;
            break;
        }
    }
}
