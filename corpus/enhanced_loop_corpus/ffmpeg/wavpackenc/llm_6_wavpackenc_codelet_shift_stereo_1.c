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
    int32_t temp_left, temp_right;
    for (i = 0; i < nb_samples; i++) {
        temp_left = left[i];
        temp_right = right[i];
        temp_left >>= shift;
        temp_right >>= shift;
        left[i] = temp_left;
        right[i] = temp_right;
    }
}
