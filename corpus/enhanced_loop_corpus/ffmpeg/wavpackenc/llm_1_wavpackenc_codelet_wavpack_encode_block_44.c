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
    if (nb_samples > 0) {
        i = 0;
        for (;;) {
            samples_r[i] += ((samples_l[i] -= samples_r[i]) >> 1);
            i++;
            if (i >= nb_samples) break;
        }
    }
}
