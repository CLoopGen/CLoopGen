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
    // Variant 2: Strided memory access with reverse traversal (stride of 1, but accessed in non-linear logical chunks)
    // Simulate strided behavior by grouping operations and changing access order in steps
    UChar *b = n->b;
    // Process elements in a reordered pattern: 7,5,3,1,6,4,2,0 (strided odd-then-even descending)
    const int indices[8] = {7, 5, 3, 1, 6, 4, 2, 0};
    for (i = 0; i < 8; i++) {
        int idx = indices[i];
        tmp = rem * 256 + b[idx];
        b[idx] = tmp / 10;
        rem = tmp % 10;
    }
}
