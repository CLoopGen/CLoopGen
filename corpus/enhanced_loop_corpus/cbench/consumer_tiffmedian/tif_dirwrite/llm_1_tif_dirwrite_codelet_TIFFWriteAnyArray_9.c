#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 n;
extern double *v;
extern int i;
extern float *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        for (i = 0; i < (int)n; i += 2) {
            bp[i] = (float)v[i];
            if (i + 1 < (int)n)
                bp[i + 1] = (float)v[i + 1];
        }
    }
}
