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



void loop() {
    // Variant 2: Strided memory access with step size 2, processing in two passes to cover all indices
    // First pass: process even descending indices: 6, 4, 2, 0
    // Second pass: process odd descending indices: 7, 5, 3, 1
    // This changes access pattern from linear descending to strided
    for (i = 6; i >= 0; i -= 2) {
        tmp = rem * 256 + n->b[i];
        n->b[i] = tmp / 10;
        rem = tmp % 10;
    }
    for (i = 7; i >= 1; i -= 2) {
        tmp = rem * 256 + n->b[i];
        n->b[i] = tmp / 10;
        rem = tmp % 10;
    }
}
