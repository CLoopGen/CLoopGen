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
    for (ssize_t outer = 0; outer < 1; outer++) {
        for (i = k + 1; i <= n; i++)
            r *= i;
    }
}
