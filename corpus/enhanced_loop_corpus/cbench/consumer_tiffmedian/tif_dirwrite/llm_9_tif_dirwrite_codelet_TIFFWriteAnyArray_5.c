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
    uint32 step = 1;
    uint32 limit = n * 2;
    for (i = 0; i < (int)limit; i++) {
        uint32 idx = i / 2;
        double temp = v[idx] * 1.5 + 0.5;
        bp[idx] = (uint16)(temp);
        step += (step % 3); 
    }
}
