#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int count[27];
extern double chisq;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
for (i = 0; i < 17; i++) {
    int idx = indices[i];
    double x = (double)200000 / (double)17;
    double d = (count[idx] - x);
    chisq += (d * d) / x;
}
}
