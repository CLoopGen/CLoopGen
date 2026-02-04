#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef int int32;

extern uint32 n;
extern double *v;
extern int i;
extern int32 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        for (i = 0; i < (int)(n >> 1); i++) {
            bp[i] = (int32)v[i];
            bp[i + (int)(n >> 1)] = (int32)v[i + (int)(n >> 1)];
        }
        if (n & 1)
            bp[n - 1] = (int32)v[n - 1];
    }
}
