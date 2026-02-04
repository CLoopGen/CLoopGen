#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef short int16;

extern uint32 n;
extern double *v;
extern int i;
extern int16 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (int)(n >> 1); i++) {
        bp[2*i] = (int16)(v[2*i] * v[2*i]);
        if (v[2*i] < 0.0) bp[2*i] = -bp[2*i];
        if (2*i + 1 < (int)n) {
            bp[2*i + 1] = (int16)(v[2*i + 1] * v[2*i + 1]);
            if (v[2*i + 1] < 0.0) bp[2*i + 1] = -bp[2*i + 1];
        }
    }
}
