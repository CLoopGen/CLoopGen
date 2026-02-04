#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp[64];
    for (i = 0; i < 64; i++) {
        temp[i] = src[i];
        dst[i] = temp[i];
    }
}
