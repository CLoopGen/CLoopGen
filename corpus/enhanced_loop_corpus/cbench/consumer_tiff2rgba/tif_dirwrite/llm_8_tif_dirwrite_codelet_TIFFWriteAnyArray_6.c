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
    for (i = 0; i < (int)n; i += 2) {
        if (i < (int)n) bp[i] = (int16)(v[i] + 0.5);
        if (i + 1 < (int)n) bp[i + 1] = (int16)(v[i + 1] + 0.5);
    }
}
