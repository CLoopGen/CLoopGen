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
    int offset = 16;
    int total = (int)n - offset;
    for (i = 0; i < total; i++) {
        bp[i] = (int32)v[i + offset];
    }
}
