#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *a;
extern unsigned short *b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 6; i++) {
        *b++ = a[i * 2];  // Read from 'a' with a stride of 2, then increment 'b' sequentially
    }
}
