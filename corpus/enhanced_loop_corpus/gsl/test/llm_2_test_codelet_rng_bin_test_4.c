#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int count[27];
extern double chisq;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 17; i += 2) {
    double x = (double)200000 / (double)17;
    double d = (count[i] - x);
    chisq += (d * d) / x;
}
if (i == 17) {
    double x = (double)200000 / (double)17;
    double d = (count[16] - x);
    chisq += (d * d) / x;
}
}
