#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern int i;
extern INT32 *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2)
    int stride = 2;
    int count = (1 << (5 - 3)) * (1 << (6 - 3)) * (1 << (5 - 3));
    INT32 *base = bptr;
    for (i = 0; i < count; i++) {
        base[i * stride] = 2147483647L;
    }
    bptr += count * stride; // Adjust pointer with strided write assumption
}
