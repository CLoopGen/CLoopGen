#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *PL_bitcount;
extern I32 bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse iteration and stride of 2
    for (bits = 254; bits >= 2; bits -= 2) {
        I32 val = bits;
        char sum = 0;
        sum += (val & 1) ? 1 : 0;
        sum += (val & 2) ? 1 : 0;
        sum += (val & 4) ? 1 : 0;
        sum += (val & 8) ? 1 : 0;
        sum += (val & 16) ? 1 : 0;
        sum += (val & 32) ? 1 : 0;
        sum += (val & 64) ? 1 : 0;
        sum += (val & 128) ? 1 : 0;
        PL_bitcount[bits] += sum;
    }
    // Handle odd indices separately to maintain full coverage
    for (bits = 255; bits >= 1; bits -= 2) {
        I32 val = bits;
        char sum = 0;
        sum += (val & 1) ? 1 : 0;
        sum += (val & 2) ? 1 : 0;
        sum += (val & 4) ? 1 : 0;
        sum += (val & 8) ? 1 : 0;
        sum += (val & 16) ? 1 : 0;
        sum += (val & 32) ? 1 : 0;
        sum += (val & 64) ? 1 : 0;
        sum += (val & 128) ? 1 : 0;
        PL_bitcount[bits] += sum;
    }
}
