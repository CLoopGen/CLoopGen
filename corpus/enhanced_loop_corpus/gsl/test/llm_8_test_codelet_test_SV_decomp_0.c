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
int end = 18;
for (i = start; i < end; i += 2) {
    a[i/2] = lower + 1.5;
}
}
