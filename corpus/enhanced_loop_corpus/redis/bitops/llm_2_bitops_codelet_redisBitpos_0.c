#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long count;
extern unsigned long *l;
extern unsigned char *c;
extern unsigned long word;
extern unsigned long j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (j = 0; j < sizeof(*l); j++) {
        word <<= 8;
        if (count >= 2) {
            word |= c[0];
            c += 2;  // Advance by stride of 2
            count -= 2;
        }
    }
}
