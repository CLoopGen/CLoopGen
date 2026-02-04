#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double y;
extern  int M;
extern double sum;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_term = 0.0;
    for (n = 1; n <= M; n++) {
        double current_term = 1. / (n * (n * n + y * y)) + prev_term;
        sum += current_term - prev_term;
        prev_term = current_term;
    }
}
