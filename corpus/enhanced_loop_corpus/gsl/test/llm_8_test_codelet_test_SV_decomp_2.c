#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double lower;
extern double *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 32; i++) {
    a[i] = lower + 1.5;
    a[i] *= 2.0;
}
}
