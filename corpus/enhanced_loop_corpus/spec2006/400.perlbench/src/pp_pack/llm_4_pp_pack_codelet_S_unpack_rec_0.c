#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *PL_bitcount;
extern I32 bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (bits = 1; bits < 256; bits++) {
        if (!(bits & 1) && !(bits & 2) && !(bits & 4) && !(bits & 8) &&
            !(bits & 16) && !(bits & 32) && !(bits & 64) && !(bits & 128)) {
            continue;
        }
        if (bits & 1)
            PL_bitcount[bits]++;
        if (bits & 2)
            PL_bitcount[bits]++;
        if (bits & 4)
            PL_bitcount[bits]++;
        if (bits & 8)
            PL_bitcount[bits]++;
        if (bits & 16)
            PL_bitcount[bits]++;
        if (bits & 32)
            PL_bitcount[bits]++;
        if (bits & 64)
            PL_bitcount[bits]++;
        if (bits & 128)
            PL_bitcount[bits]++;
    }
}
