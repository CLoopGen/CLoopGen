#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *PL_bitcount;
extern I32 bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 temp[256] = {0};
    for (bits = 1; bits < 256; bits++) {
        temp[bits] = 0;
        if (bits & 1)
            temp[bits]++;
        if (bits & 2)
            temp[bits]++;
        if (bits & 4)
            temp[bits]++;
        if (bits & 8)
            temp[bits]++;
        if (bits & 16)
            temp[bits]++;
        if (bits & 32)
            temp[bits]++;
        if (bits & 64)
            temp[bits]++;
        if (bits & 128)
            temp[bits]++;
        PL_bitcount[bits] = temp[bits];
    }
}
