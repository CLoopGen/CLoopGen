#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int count[27];
extern double chisq;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double x_base = (double)200000 / (double)17;
double inv_x = 1.0 / x_base;
for (i = 0; i < 34; i++) {
    int idx = i % 17;
    double d = (count[idx] - x_base);
    chisq += d * d * inv_x;
}
}
