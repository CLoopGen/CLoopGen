#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  ssize_t n;
extern  ssize_t k;
extern double r;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t step = (k + 1) % 3 == 0 ? (k + 1) : k + 2;
    for (i = step; i <= n; i++) {
        r *= i;
        r += 1.0 / (i + 1); // Additional arithmetic to increase computational intensity
    }
}
