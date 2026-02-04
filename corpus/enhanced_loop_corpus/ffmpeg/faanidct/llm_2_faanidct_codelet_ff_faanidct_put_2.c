#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FLOAT;

extern  FLOAT prescale[64];
extern int16_t block[64];
extern FLOAT temp[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    for (i = 0; i < 64; i += 2) {
        temp[i] = block[i] * prescale[i];
        if (i + 1 < 64) {
            temp[i + 1] = block[i + 1] * prescale[i + 1];
        }
    }
}
