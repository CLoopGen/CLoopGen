#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern int rem;
extern unsigned char *ovec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride
    // Instead of accessing consecutive elements, we now read from a strided pattern in the source
    int stride = num + 2; // Modify access pattern by increasing effective stride
    for (i = 0; i < 8; ++i)
        ovec[i] = ovec[i * stride + num] << rem | ovec[i * stride + num + 1] >> (8 - rem);
}
