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
    for (i = 1; i <= (n - k); i++) {
        if (i % 2 == 0) continue;
        r /= i;
        if (r < 1e-10) break;
    }
}
