#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern double value;
extern ssize_t i;
extern ssize_t n;
extern ssize_t order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_value = 1.0;
    for (i = 0; i < order; i++) {
        double factor = 1.0;
        if (i != n) {
            factor = (n - i - x) / (n - i);
        }
        local_value *= factor;
    }
    value *= local_value;
}
