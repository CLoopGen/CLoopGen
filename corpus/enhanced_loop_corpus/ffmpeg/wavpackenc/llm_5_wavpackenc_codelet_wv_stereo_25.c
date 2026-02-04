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
    int found = 0;
    for (i = 0; i < nb_samples && !found; i++)
        found = (samples_l[i] != 0) | (samples_r[i] != 0);
    if (found)
        i--;
}
