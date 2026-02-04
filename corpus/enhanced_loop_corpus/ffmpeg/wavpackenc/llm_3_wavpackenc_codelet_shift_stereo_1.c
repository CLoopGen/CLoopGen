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
    // Variant 2: Reverse sequential access (backward traversal)
    for (i = nb_samples - 1; i >= 0; i--) {
        left[i] >>= shift;
        right[i] >>= shift;
    }
}
