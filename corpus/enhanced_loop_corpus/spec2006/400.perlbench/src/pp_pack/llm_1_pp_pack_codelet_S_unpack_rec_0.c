#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *PL_bitcount;
extern I32 bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (bits = 1; bits < 64; bits++) {
        for (I32 step = 0; step < 4; step++) {
            I32 val = bits + (step * 64);
            if (val >= 256) break;
            if (val & 1)
                PL_bitcount[val]++;
            if (val & 2)
                PL_bitcount[val]++;
            if (val & 4)
                PL_bitcount[val]++;
            if (val & 8)
                PL_bitcount[val]++;
            if (val & 16)
                PL_bitcount[val]++;
            if (val & 32)
                PL_bitcount[val]++;
            if (val & 64)
                PL_bitcount[val]++;
            if (val & 128)
                PL_bitcount[val]++;
        }
    }
}
