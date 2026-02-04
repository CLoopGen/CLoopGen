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
    uint32 stride = 4;
    for (i = 0; i < (int)n; i++) {
        double sum = v[i];
        double scaled = sum * 1.5;
        bp[i] = (uint16)(scaled + 0.5);
        for (uint32 j = 1; j < stride && (i + j) < (int)n; j++) {
            bp[i] += (uint16)(v[i+j] * 1.5 + 0.5);
        }
    }
}
