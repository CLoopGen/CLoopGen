#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int16_t indices[] = {0, 1, 2, 3, 4, 5, 6, 7};
    for (int j = 0; j < 8; j++) {
        int idx = indices[j];
        int a0 = ptr[idx];
        int a1 = ptr[8 + idx];
        ptr[idx] = a0 + a1;
        ptr[8 + idx] = a0 - a1;
    }
    ptr += 2 * 8;
}
}
