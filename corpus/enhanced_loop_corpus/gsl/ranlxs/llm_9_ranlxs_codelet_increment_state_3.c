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
    for (k = next[ir]; k > 0 && k < 10; k = next[next[k]]) {
        double temp1 = xdbl[k] + shift;
        double temp2 = xdbl[next[k]] + shift;
        ydbl[k] = temp1;
        if (next[k] > 0) {
            ydbl[next[k]] = temp2;
        }
    }
}
