#include <stdio.h>

#include <inttypes.h>

extern int64_t cond[5];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2, then handle odd indices in second pass)
    unsigned int i;
    for (i = 0; i < 5; i += 2)
        cond[i] = ((cond[i] & 72057594037927935L) - 1) >> 63;
    
    for (i = 1; i < 5; i += 2)
        cond[i] = ((cond[i] & 72057594037927935L) - 1) >> 63;
}
