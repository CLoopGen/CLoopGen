#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double lower;
extern double *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double factor = 2.0;
double increment = 0.1;
double temp = lower;
for (i = 0; i < 18; i++) {
    temp = temp * factor + increment;
    a[i % 9] = temp;
}
}
