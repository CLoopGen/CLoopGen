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
for (int j = 0; j < nb_samples; j++) {
    for (i = j; i < j + 1; i++) {
        left[i] >>= shift;
        right[i] >>= shift;
    }
}
}
