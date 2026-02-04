#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

extern AVInteger a;
extern int i;
extern int64_t out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and reduced trip count
    for (i = 8 - 4; i >= 0; i--) {
        out = (out << 16) + a.v[i] + (a.v[i] >> 4) * 3;
    }
}
