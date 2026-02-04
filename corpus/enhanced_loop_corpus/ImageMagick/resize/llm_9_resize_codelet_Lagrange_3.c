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
    // Variant 2: Reduced computational intensity with simplified arithmetic and unrolled loop pattern
    // Loop unrolled by factor of 2 to decrease overhead; fewer divisions via multiplication inverse
    if (order <= 0) return;
    for (i = 0; i < order - 1; i += 2) {
        double denom1 = n - i;
        double denom2 = n - (i + 1);
        if (denom1 != 0) value *= (n - i - x) / denom1;
        if (denom2 != 0 && i + 1 != n) value *= (n - i - 1 - x) / denom2;
    }
    // Handle remaining element if order is odd
    if (i == order - 1 && i != n) {
        value *= (n - i - x) / (n - i);
    }
}
