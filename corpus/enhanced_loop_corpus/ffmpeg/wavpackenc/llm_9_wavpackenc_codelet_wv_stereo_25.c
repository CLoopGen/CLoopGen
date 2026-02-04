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
    int limit = nb_samples >> 1;
    for (i = 0; i < limit; i++) {
        int32_t sum_l = samples_l[i] + samples_l[nb_samples - 1 - i];
        int32_t sum_r = samples_r[i] + samples_r[nb_samples - 1 - i];
        if (sum_l || sum_r)
            break;
    }
}
