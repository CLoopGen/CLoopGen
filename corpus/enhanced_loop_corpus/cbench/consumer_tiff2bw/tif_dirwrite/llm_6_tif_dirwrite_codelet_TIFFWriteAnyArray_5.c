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
    uint16 *local_bp = bp;
    double *local_v = v;
    for (int j = 0; j < (int)temp_n; j++) {
        local_bp[j] = (uint16)local_v[j];
    }
}
