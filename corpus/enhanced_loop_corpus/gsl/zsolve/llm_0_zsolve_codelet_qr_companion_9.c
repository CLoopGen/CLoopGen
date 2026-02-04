#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *h;
extern size_t nc;
extern size_t i;
extern double x;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < 1; j++) {
        for (i = 1; i <= n; i++) {
            ((h)[((i) - 1) * (nc) + ((i) - 1)]) -= x;
        }
    }
}
