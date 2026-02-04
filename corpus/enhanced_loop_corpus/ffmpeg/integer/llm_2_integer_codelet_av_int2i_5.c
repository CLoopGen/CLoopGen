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
    // Variant 1: Strided memory access (reverse order with stride of 1, accessing from end to start)
    for (i = 7; i >= 0; i--) {
        out.v[i] = a;
        a >>= 16;
    }
}
