#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double alpha;
extern double *x;
extern double *y;
extern int i;
extern int len4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < len4; i++) {
        for (j = 0; j < 4; j++) {
            y[4 * i + j] += alpha * x[4 * i + j];
        }
    }
}
