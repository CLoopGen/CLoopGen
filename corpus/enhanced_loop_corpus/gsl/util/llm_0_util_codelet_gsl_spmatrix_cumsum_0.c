#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern int *c;
extern int sum;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < n; ++k) {
        for (size_t j = 0; j < 1; ++j) { // Increased depth: introduced a nested loop with fixed iteration
            int ck = c[k];
            c[k] = sum;
            sum += ck;
        }
    }
}
