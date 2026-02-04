#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *vec;
extern int bits;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i += 2) {
        if (i + 1 < size) {
            vec[i]     = vec[i]     * (1 << bits);
            vec[i + 1] = vec[i + 1] * (1 << bits);
        } else {
            vec[i] = vec[i] * (1 << bits);
        }
    }
}
