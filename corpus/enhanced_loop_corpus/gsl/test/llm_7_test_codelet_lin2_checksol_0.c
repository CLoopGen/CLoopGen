#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x[];
extern size_t i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev = 0.0;
    for (i = 0; i < 5; ++i) {
        double current = (i + 1.) * x[i] + prev;
        sum += current;
        prev = current;
    }
}
