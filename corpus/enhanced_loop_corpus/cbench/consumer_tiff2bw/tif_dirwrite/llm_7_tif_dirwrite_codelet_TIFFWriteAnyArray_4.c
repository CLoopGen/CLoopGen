#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef signed char int8;

extern uint32 n;
extern double *v;
extern int i;
extern int8 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 j;
    int8 prev = 0;
    for (j = 0; j < n; j++) {
        bp[j] = (int8)(v[j]) + prev;
        prev = bp[j];
    }
}
