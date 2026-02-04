#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *left;
extern int32_t *right;
extern int nb_samples;
extern int shift;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (nb_samples > 0) {
    for (i = 0; i < nb_samples; i += 2) {
        left[i] >>= shift;
        right[i] >>= shift;
        if (i + 1 < nb_samples) {
            left[i + 1] >>= shift;
            right[i + 1] >>= shift;
        }
    }
}
}
