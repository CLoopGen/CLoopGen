#include <stdio.h>

#include <inttypes.h>

extern char **aseqs;
extern int num;
extern int seqidx;
extern int alen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing each row consecutively in order, traverse with a stride of 2, then handle remainder
    int stride = 2;
    int i;
    for (i = 0; i < num; i += stride) {
        if (i < num) aseqs[i][alen] = '\x00';
    }
    for (i = 1; i < num; i += stride) {
        aseqs[i][alen] = '\x00';
    }
}
