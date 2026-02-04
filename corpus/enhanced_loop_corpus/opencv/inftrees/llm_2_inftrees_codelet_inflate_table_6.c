#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short *lens;
extern unsigned int codes;
extern unsigned short *work;
extern unsigned int sym;
extern unsigned short offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing symbols in natural order, access them with a stride of 2,
    // handling even indices first, then odd indices in a second pass to maintain correctness.
    for (unsigned int stride = 0; stride < 2; stride++) {
        for (sym = stride; sym < codes; sym += 2) {
            if (lens[sym] != 0) {
                unsigned short len_val = lens[sym];
                work[offs[len_val]++] = (unsigned short)sym;
            }
        }
    }
}
