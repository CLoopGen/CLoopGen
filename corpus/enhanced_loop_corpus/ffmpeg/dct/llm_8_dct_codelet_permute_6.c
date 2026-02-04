#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        dst[2*i] = src[2*i];
        dst[2*i + 1] = src[2*i + 1];
    }
}
