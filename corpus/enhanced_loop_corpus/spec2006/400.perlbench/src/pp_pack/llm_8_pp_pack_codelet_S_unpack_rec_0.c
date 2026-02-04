#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *PL_bitcount;
extern I32 bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (bits = 0; bits < 512; bits += 2) {
        PL_bitcount[bits + 1]++;
        PL_bitcount[bits + 1]++;
        PL_bitcount[bits + 1]++;
        PL_bitcount[bits + 1]++;
        PL_bitcount[bits + 1]++;
        PL_bitcount[bits + 1]++;
        PL_bitcount[bits + 1]++;
        if (bits + 1 < 256) {
            PL_bitcount[bits + 1]++;
        }
    }
}
