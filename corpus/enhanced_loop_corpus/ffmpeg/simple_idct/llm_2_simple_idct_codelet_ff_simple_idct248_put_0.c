#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int16_t *base = ptr;
    for (int j = 0; j < 8; j++) {
        int a0 = base[j];
        int a1 = base[8 + j];
        base[j] = a0 + a1;
        base[8 + j] = a0 - a1;
    }
    ptr += 2 * 8;
}
}
