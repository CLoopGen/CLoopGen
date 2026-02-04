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
    // Variant 2: Indirect memory access via index mapping (reverse order access using an index array)
    Int32 indices[8] = {7, 6, 5, 4, 3, 2, 1, 0}; // Reverse access pattern
    sum = 0.0;
    base = 1.0;
    Int32 j;
    for (j = 0; j < 8; j++) {
        Int32 idx = indices[j]; // Indirect access through index map
        sum += base * (double)(n->b[idx]);
        base *= 256.0;
    }
}
