#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *PL_bitcount;
extern I32 bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using a pointer walk
    char *ptr = PL_bitcount + 1;
    for (bits = 1; bits < 256; bits++) {
        I32 count = 0;
        I32 temp = bits;
        while (temp) {
            count += temp & 1;
            temp >>= 1;
        }
        *ptr++ += count;
    }
}
