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
for (i = 0; i < nb_samples; i++) {
    int32_t sl = samples_l[i];
    int32_t sr = samples_r[i];
    lor |= sl | sr;
    diff |= sl - sr;
    if (!lor && !diff) continue;
    else break;
}
}
