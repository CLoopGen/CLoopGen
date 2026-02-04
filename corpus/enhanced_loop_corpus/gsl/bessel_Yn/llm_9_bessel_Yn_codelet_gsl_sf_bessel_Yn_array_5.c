#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i, j;
int range = nmax - nmin + 1;
for (i = nmin; i <= nmax; i++) {
    double sum = 0.0;
    for (j = 0; j < 4; j++) {
        sum += (double)(i & (1 << j));
    }
    result_array[i - nmin] = sum / 4.0;
}
}
