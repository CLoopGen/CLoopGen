#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef unsigned char uint8;

extern uint32 n;
extern double *v;
extern int i;
extern uint8 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 local_n = n;
    uint8 *local_bp = bp;
    double *local_v = v;
    for (i = 0; i < (int)local_n; i++) {
        uint8 temp = (uint8)local_v[i];
        local_bp[i] = temp;
    }
}
