#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double sum = 0.0;
    for (n = 0; n < 25; n++) {
        t[2*n] = (n == 0) ? 1.23 : 0.;
        t[2*n + 1] = 0.;
        sum += t[2*n] * t[2*n] + t[2*n + 1] * t[2*n + 1];
    }
    t[49] += sum * 0.01;
}
