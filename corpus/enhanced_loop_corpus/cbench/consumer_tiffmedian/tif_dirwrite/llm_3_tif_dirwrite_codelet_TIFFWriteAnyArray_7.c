#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 n;
extern double *v;
extern int i;
extern uint32 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 *indices = bp; // assume bp can also serve as index array for indirect access
    for (i = 0; i < (int)n; i++) {
        uint32 idx = indices[i];
        if (idx < n) bp[idx] = (uint32)v[idx];
    }
}
