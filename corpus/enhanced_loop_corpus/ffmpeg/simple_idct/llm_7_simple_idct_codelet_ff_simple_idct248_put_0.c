#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int16_t a0, a1;
    for (int j = 0; j < 8; j++) {
        a0 = ptr[j];
        a1 = ptr[8 + j];
        ptr[8 + j] = a0 - a1;
        ptr[j]     = a0 + a1;
    }
    ptr += 2 * 8;
}
}
