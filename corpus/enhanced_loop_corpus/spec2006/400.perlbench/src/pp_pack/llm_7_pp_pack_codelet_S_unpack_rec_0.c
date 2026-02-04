#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *PL_bitcount;
extern I32 bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_bitcount = PL_bitcount;
    I32 accumulated = 0;
    for (bits = 1; bits < 256; bits++) {
        accumulated += bits; // Introduce loop-carried dependency (WAW and RAW)
        if ((accumulated ^ bits) & 1)
            local_bitcount[bits]++;
        if ((accumulated ^ bits) & 2)
            local_bitcount[bits]++;
        if ((accumulated ^ bits) & 4)
            local_bitcount[bits]++;
        if ((accumulated ^ bits) & 8)
            local_bitcount[bits]++;
        if ((accumulated ^ bits) & 16)
            local_bitcount[bits]++;
        if ((accumulated ^ bits) & 32)
            local_bitcount[bits]++;
        if ((accumulated ^ bits) & 64)
            local_bitcount[bits]++;
        if ((accumulated ^ bits) & 128)
            local_bitcount[bits]++;
    }
}
