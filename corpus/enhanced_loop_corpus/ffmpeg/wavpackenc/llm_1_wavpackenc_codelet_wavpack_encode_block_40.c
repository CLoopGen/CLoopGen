#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples_l;
extern int32_t *samples_r;
extern int i;
extern int nb_samples;
extern int32_t lor;
extern int32_t diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nb_samples > 0) {
        int i = 0;
        do {
            lor |= samples_l[i] | samples_r[i];
            diff |= samples_l[i] - samples_r[i];
            if (lor && diff)
                break;
            i++;
        } while (i < nb_samples);
    }
}
