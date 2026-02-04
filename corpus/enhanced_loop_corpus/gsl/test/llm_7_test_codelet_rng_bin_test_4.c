#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int count[27];
extern double chisq;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp_chisq = 0.0;
double x = (double)200000 / (double)17;
for (i = 0; i < 17; i++) {
    double d = (count[i] - x);
    temp_chisq += (d * d) / x;
}
chisq += temp_chisq;
}
