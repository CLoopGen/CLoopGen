#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern int M;
extern double sum;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (m = 0; m < M; m += 2) {
        if (m + 1 < M) {
            sum += 1. / ((x + m) * (x + m)) + 1. / ((x + m + 1) * (x + m + 1));
        } else {
            sum += 1. / ((x + m) * (x + m));
        }
    }
}
