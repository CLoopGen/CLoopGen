#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 prime[];
extern int32 size;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    int32 idx = 0;
    for (i = 0; (idx < size) && (prime[idx] > 0) && (prime[idx] < size); i++, idx += 2)
        ;
}
