#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern double s;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    double s1 = s * 1.01;
    double s2 = s * 0.99;
    for (i = 0; i < len; i++) {
        dp1[i] += s1 * dp2[i] + s2 * dp1[i] * 0.01;
    }
}
