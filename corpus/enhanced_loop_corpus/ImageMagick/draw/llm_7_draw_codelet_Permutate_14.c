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
    double local_r = 1.0;
    for (i = k + 1; i <= n; i++) {
        local_r *= i;
        r = local_r; // Introduce WAW dependency on 'r', updated every iteration
    }
}
