#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef struct {
    UChar b[8];
} UInt64;

typedef unsigned int UInt32;

typedef int Int32;

extern UInt64 *n;
extern UInt32 rem;
extern UInt32 tmp;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, with wrap-around handling using modulo)
    // The array access is now strided by 2, traversing in reverse order with modulo indexing
    UChar indices[8] = {7, 5, 3, 1, 6, 4, 2, 0}; // Reverse strided pattern: step -2 mod 8
    for (i = 0; i < 8; i++) {
        Int32 idx = indices[i];
        tmp = rem * 256 + n->b[idx];
        n->b[idx] = tmp / 10;
        rem = tmp % 10;
    }
}
