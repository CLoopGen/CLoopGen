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
    double temp_value;
    for (k = next[ir]; k > 0; ) {
        temp_value = xdbl[k] + shift;
        ydbl[k] = temp_value;
        k = next[k];
    }
}
