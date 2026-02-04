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
    uint32 temp_n = n;
    double *temp_v = v;
    uint16 *temp_bp = bp;
    for (i = 0; i < (int)temp_n; i++) {
        temp_bp[i] = (uint16)temp_v[i];
    }
}
