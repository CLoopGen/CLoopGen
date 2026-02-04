#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

typedef int I32;

extern U8 *tmps;
extern I32 anum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive dual-byte access using pointer arithmetic with temporary
    U8 *ptr = tmps;
    for (; anum > 0; anum--, ptr++)
        if (anum >= 2) {
            *ptr = ~*ptr;
            *(ptr+1) = ~*(ptr+1);
            anum--;
        } else {
            *ptr = ~*ptr;
        }
    tmps = ptr;
}
