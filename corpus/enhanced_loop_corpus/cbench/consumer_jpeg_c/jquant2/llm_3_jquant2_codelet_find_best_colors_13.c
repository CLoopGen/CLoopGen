#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern int i;
extern INT32 *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write every 4th element, then repeat with offset (simulating stride pattern)
    int stride = 4;
    int count = (1 << (5 - 3)) * (1 << (6 - 3)) * (1 << (5 - 3));
    int full_length = count * stride;
    INT32 *temp = bptr;

    // Perform strided initialization: write to temp[0], temp[4], temp[8], ...
    for (i = 0; i < full_length; i += stride) {
        temp[i] = 2147483647L;
    }
    bptr += full_length;  // Advance bptr as if all written elements are consumed
}
