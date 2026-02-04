#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int count[27];
extern double chisq;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double x = (double)200000 / (double)17;
for (i = 0; i < 17; i++) {
    double d = ((double)count[i] - x);
    chisq += (d * d) / x;
}
}
