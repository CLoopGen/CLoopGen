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
    int j;
    for (i = 0; i < nb_samples; i++) {
        left[i] >>= shift;
        right[i] >>= shift;
        for (j = 0; j < shift; j++) {
            left[i] += (left[i] & 1) ? 0 : 1;
        }
    }
}
