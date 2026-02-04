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
    for (i = 0; i < (int)n; i++) {
        double temp = v[i] * 1.5 + 0.5;
        bp[i] = (uint16)(temp < 65535.0 ? temp : 65535.0);
    }
}
