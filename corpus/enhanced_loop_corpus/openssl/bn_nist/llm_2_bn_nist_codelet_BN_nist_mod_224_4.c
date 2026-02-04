#include <stdio.h>

#include <inttypes.h>

extern unsigned long c_d[4];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This accesses every second element in c_d, writing zero to each
    for (; ii < (224 + (8 * 8) - 1) / (8 * 8); ii += 2)
        (c_d)[ii] = 0;
}
