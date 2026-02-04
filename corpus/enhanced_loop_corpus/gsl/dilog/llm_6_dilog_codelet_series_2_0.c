#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double r;
extern double rk;
extern double sum;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = 0.0;
    double rk_local = rk;
    for (k = 2; k < 10; k++) {
        double ds;
        ds = rk_local / (k * k * (k + 1.));
        temp_sum += ds;
        rk_local *= r;
    }
    sum += temp_sum;
}
