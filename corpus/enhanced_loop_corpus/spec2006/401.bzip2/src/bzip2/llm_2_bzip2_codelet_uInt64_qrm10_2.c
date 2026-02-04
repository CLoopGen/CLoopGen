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
    // Variant 1: Reverse memory access pattern with consecutive indexing (unrolled-like forward traversal using offset arithmetic)
    UChar *b = n->b;
    for (i = 0; i < 8; i++) {
        int idx = 7 - i;  // Reverse the index access: now traversing backwards via forward loop
        tmp = rem * 256 + b[idx];
        b[idx] = tmp / 10;
        rem = tmp % 10;
    }
}
