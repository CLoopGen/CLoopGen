#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 n;
extern double *v;
extern int i;
extern uint32 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (int)n; i += 2) {
        if (i + 1 < (int)n) {
            bp[i] = (uint32)(v[i] * 1.5 + 0.5);
            bp[i+1] = (uint32)(v[i+1] * 1.5 + 0.5);
        } else {
            bp[i] = (uint32)(v[i] * 1.5 + 0.5);
        }
    }
}
