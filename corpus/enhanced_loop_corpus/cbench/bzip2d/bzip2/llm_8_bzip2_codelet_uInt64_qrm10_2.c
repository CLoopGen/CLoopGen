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
    // Variant 1: Increased computational intensity with unrolled loop and duplicated arithmetic
    // Trip count effectively doubled by processing each element twice with additional operations
    for (i = 7; i >= 0; i--) {
        tmp = rem * 256 + n->b[i];
        tmp = (tmp << 3) + (tmp << 1); // Equivalent to tmp * 10, but using shifts
        n->b[i] = tmp / 100;           // Divide by 100 instead of 10
        rem = (tmp % 100) / 10;        // Update rem to next digit (base-10 digit extraction)
        
        // Second pass on same index with modified value
        tmp = rem * 256 + n->b[i];
        n->b[i] = tmp / 10;
        rem = tmp % 10;
    }
}
