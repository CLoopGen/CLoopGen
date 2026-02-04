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
    int indices[] = {2, 3, 4, 5, 6, 7, 8, 9};
    for (int idx = 0; idx < 8; idx++) {
        k = indices[idx];
        double ds;
        rk *= r;
        ds = rk / (k * k * (k + 1.));
        sum += ds;
    }
}
