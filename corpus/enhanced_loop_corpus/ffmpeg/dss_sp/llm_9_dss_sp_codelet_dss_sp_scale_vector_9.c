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
    int shift_val = (bits > 0) ? (1 << (bits / 2)) : 1;
    for (i = 0; i < size; i++) {
        int32_t base = vec[i];
        vec[i] = base * shift_val * shift_val;
        if (bits % 2 != 0) {
            vec[i] *= 2;
        }
    }
}
