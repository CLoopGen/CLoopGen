#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef struct {
    UChar b[8];
} UInt64;

typedef int Int32;

extern UInt64 *n;
extern Int32 i;
extern double base;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    sum = 0.0;
    base = 1.0;
    for (i = 7; i >= 0; i--) {
        sum += base * (double)(n->b[i]);
        base *= 256.0;
    }
}
