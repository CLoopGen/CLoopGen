#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double lower;
extern double *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int start = 0;
int step = 1;
for (i = start; i < 9; i += step) {
    a[i] = lower + (double)(i * i) / 2.0;
}
}
