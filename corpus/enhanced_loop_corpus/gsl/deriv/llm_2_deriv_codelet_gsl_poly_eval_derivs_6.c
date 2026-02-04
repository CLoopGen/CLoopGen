#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double res[];
extern size_t i;
extern size_t nmax;
extern double f;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (access every 2nd element)
    for (i = 2; i <= nmax; i += 2) {
        f *= i;
        res[i] *= f;
        if (i + 1 <= nmax) {
            f *= (i + 1);
            res[i + 1] *= f;
        }
    }
}
