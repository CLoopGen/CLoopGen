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
    // Variant 2: Reduced trip count with simplified logic and fewer operations per iteration
    // Loop runs only 4 times instead of 8, skipping every other byte
    for (i = 6; i >= 0; i -= 2) {
        tmp = rem * 256 + n->b[i];     // Only process even indices
        n->b[i] = tmp / 10;
        rem = tmp % 10;
    }
    // Final cleanup on last byte if needed
    tmp = rem * 256;
    n->b[7] = tmp / 10;
    rem = tmp % 10;
}
