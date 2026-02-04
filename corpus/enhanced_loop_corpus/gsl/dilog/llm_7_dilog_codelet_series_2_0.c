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
    double prev_rk = rk;
    for (k = 2; k < 10; k++) {
        double ds;
        double current_rk = prev_rk * r;
        ds = current_rk / (k * k * (k + 1.));
        sum += ds;
        prev_rk = current_rk;
    }
    rk = prev_rk;
}
