#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int next[12];
extern  double shift;
extern int k;
extern double *xdbl;
extern double *ydbl;
extern unsigned int ir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = next[ir]; k > 0; k = next[k]) {
        if (k % 2 == 0) {
            ydbl[k] = xdbl[k] + shift;
        } else {
            continue;
        }
    }
}
