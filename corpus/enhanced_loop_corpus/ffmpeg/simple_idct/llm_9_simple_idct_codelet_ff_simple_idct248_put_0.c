#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    int j;
    for (j = 0; j < 8; j += 2) {
        int a0_0, a1_0, a0_1, a1_1;
        a0_0 = ptr[j];
        a1_0 = ptr[8 + j];
        a0_1 = ptr[j + 1];
        a1_1 = ptr[8 + j + 1];

        ptr[j] = a0_0 + a1_0;
        ptr[8 + j] = a0_0 - a1_0;
        ptr[j + 1] = a0_1 + a1_1;
        ptr[8 + j + 1] = a0_1 - a1_1;
    }
    ptr += 2 * 8;
}
}
