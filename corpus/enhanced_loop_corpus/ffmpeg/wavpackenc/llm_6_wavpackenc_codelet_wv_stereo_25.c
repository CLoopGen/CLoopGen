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
    int temp_l = 0, temp_r = 0;
    for (i = 0; i < nb_samples; i++) {
        temp_l = samples_l[i];
        temp_r = samples_r[i];
        if (temp_l || temp_r)
            break;
    }
}
