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
    double s_local = s * 1.001; // Slight variation in computation
    for (i = 0; i < len; i++) {
        double temp = s_local * (*dp2++);
        *dp1++ += temp + temp; // Double the scaled value instead of single
    }
}
