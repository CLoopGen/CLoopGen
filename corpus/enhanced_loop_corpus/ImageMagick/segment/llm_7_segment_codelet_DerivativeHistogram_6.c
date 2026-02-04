#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern double *derivative;
extern ssize_t i;
extern ssize_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_hist = histogram[0];
    double curr_hist = histogram[1];
    for (i = 1; i < n; i++) {
        double next_hist = (i + 1 < n) ? histogram[i + 1] : curr_hist;
        derivative[i] = (next_hist - prev_hist) / 2.;
        prev_hist = curr_hist;
        curr_hist = next_hist;
    }
}
