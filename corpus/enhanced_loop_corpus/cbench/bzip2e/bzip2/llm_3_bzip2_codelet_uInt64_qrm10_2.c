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
    // Variant 2: Consecutive forward traversal with reversed data interpretation
    // Instead of processing from b[7] to b[0], process b[0] to b[7]
    // This changes the memory access pattern to sequential increasing order
    for (i = 0; i <= 7; i++) {
        tmp = rem * 256 + n->b[i];
        n->b[i] = tmp / 10;
        rem = tmp % 10;
    }
}
