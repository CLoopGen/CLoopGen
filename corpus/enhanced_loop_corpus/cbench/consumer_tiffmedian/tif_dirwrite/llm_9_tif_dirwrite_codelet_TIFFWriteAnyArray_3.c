#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef unsigned char uint8;

extern uint32 n;
extern double *v;
extern int i;
extern uint8 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 j;
    for (i = 0; i < (int)n; i++) {
        double sum = v[i];
        for (j = 1; j < 4 && (i + j) < n; j++) {
            sum += v[i + j];
        }
        bp[i] = (uint8)(sum / (j));
    }
}
