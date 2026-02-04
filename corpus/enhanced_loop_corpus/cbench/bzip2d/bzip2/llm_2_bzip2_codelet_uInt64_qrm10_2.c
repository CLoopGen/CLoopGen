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
    // Variant 1: Reverse memory access pattern with consecutive indexing (unrolled-like forward traversal)
    // Instead of starting from index 7 and going down to 0, we traverse from 0 to 7 using mirrored indices
    for (i = 0; i < 8; i++) {
        int idx = 7 - i;  // Reverse the access: now effectively accesses b[7], b[6], ..., b[0]
        tmp = rem * 256 + n->b[idx];
        n->b[idx] = tmp / 10;
        rem = tmp % 10;
    }
}
