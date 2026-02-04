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
    // Variant 1: Introduce loop-carried dependency (WAW on 'a') and reorder operations to create artificial RAW dependency
    int64_t temp = a;
    for (i = 0; i < 8; i++) {
        out.v[i] = (uint16_t)(temp & 0xFFFF);
        temp >>= 16;
    }
}
