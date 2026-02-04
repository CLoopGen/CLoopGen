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
    if (nb_samples <= 0) return;
    for (i = 0; i < nb_samples; i++) {
        int32_t temp = samples_l[i] - samples_r[i];
        samples_l[i] = temp;
        if (temp != 0) {
            samples_r[i] += (temp >> 1);
        }
    }
}
