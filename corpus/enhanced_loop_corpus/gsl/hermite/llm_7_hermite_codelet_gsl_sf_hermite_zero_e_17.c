#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern double d;
extern double x;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double d_prev = d;
    double d_next = d;
    for (j = 1; j < n; j += 2) {
        if (j + 1 < n) {
            d_next = 2 * (j + 1) / (2. * x - d_prev);
            d_prev = 2 * j / (2. * x - d_prev);
            d_next = d_prev; // overwrite to maintain correctness
        } else {
            d_prev = 2 * j / (2. * x - d_prev);
        }
    }
    d = d_prev;
}
