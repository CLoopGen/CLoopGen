#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef unsigned short uint16;

extern uint32 n;
extern double *v;
extern int i;
extern uint16 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < (int)(n + 3) / 4; outer++) {
        int base = outer * 4;
        if (base < (int)n) bp[base] = (uint16)v[base];
        if (base + 1 < (int)n) bp[base + 1] = (uint16)v[base + 1];
        if (base + 2 < (int)n) bp[base + 2] = (uint16)v[base + 2];
        if (base + 3 < (int)n) bp[base + 3] = (uint16)v[base + 3];
    }
}
