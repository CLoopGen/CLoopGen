#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int16_t temp[16];
    for (int j = 0; j < 8; j++) {
        temp[j]     = ptr[j];
        temp[j + 8] = ptr[j + 8];
    }
    for (int j = 0; j < 8; j++) {
        ptr[j]     = temp[j] + temp[j + 8];
        ptr[j + 8] = temp[j] - temp[j + 8];
    }
    ptr += 2 * 8;
}
}
