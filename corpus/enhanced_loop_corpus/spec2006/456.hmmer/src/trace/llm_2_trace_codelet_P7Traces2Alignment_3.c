#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int *inserts;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (k = 0; k <= mlen; k += 2)
        inserts[k] = 0;
    
    // Handle odd-sized mlen by ensuring the last element is set if needed
    if (mlen % 2 == 0 && mlen > 0)
        inserts[mlen] = 0;
}
