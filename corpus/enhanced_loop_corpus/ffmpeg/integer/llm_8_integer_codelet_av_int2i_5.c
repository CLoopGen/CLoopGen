#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

extern int64_t a;
extern AVInteger out;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and doubled effective trip count via unrolling
    int j;
    for (i = 0; i < 4; i++) {
        j = i * 2;
        out.v[j]     = (a >> (j * 16)) & 0xFFFF;
        out.v[j + 1] = (a >> ((j + 1) * 16)) & 0xFFFF;
    }
}
