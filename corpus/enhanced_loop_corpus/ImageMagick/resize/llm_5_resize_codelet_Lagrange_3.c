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
    for (i = 0; i < order; i++) {
        if (i == n) continue;
        double numerator = n - i - x;
        double denominator = n - i;
        if (denominator != 0) {
            value *= numerator / denominator;
        }
    }
}
