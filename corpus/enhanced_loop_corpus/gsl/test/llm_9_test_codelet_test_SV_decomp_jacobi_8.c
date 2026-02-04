#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double lower;
extern double *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp;
for (i = 0; i < 18; i++) {
    temp = lower * 1.5 - 0.7;
    a[i % 9] = temp;
}
}
