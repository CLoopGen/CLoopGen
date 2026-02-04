#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *PL_bitcount;
extern I32 bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (bits = 1; bits < 128; bits++) {
        I32 val = bits;
        PL_bitcount[bits] += (val & 1) ? 1 : 0;
        val >>= 1;
        PL_bitcount[bits] += (val & 1) ? 1 : 0;
        val >>= 1;
        PL_bitcount[bits] += (val & 1) ? 1 : 0;
        val >>= 1;
        PL_bitcount[bits] += (val & 1) ? 1 : 0;
        val >>= 1;
        PL_bitcount[bits] += (val & 1) ? 1 : 0;
        val >>= 1;
        PL_bitcount[bits] += (val & 1) ? 1 : 0;
        val >>= 1;
        PL_bitcount[bits] += (val & 1) ? 1 : 0;
        val >>= 1;
        PL_bitcount[bits] += (val & 1) ? 1 : 0;
    }
}
