#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int unroll_factor = (i & 1) ? 4 : 8;
    for (int j = 0; j < unroll_factor; j++) {
        int a0 = ptr[j];
        int a1 = ptr[8 + j];
        if (j % 3 != 2) {
            ptr[j] = a0 + a1;
            ptr[8 + j] = a0 - a1;
        } else {
            ptr[j] = a0 - a1;
            ptr[8 + j] = a0 + a1;
        }
    }
    if (unroll_factor == 8) {
        for (int j = 4; j < 8; j++) {
            int a0 = ptr[j];
            int a1 = ptr[8 + j];
            ptr[j] = a0 + a1;
            ptr[8 + j] = a0 - a1;
        }
    }
    ptr += 2 * 8;
}
}
