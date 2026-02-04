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
    // Variant 2: Eliminate loop-carried dependency on 'a' by precomputing all values outside the loop
    int64_t local_a = a;
    uint16_t vals[8];
    for (int j = 0; j < 8; j++) {
        vals[j] = (uint16_t)(local_a >> (j * 16));
    }
    for (i = 0; i < 8; i++) {
        out.v[i] = vals[i];
    }
}
