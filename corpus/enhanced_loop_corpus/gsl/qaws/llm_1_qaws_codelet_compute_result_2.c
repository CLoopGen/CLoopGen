#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *r;
extern  double *cheb24;
extern size_t i;
extern double res24;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i++) {
        for (size_t j = 0; j < 5; j++) {
            size_t idx = i * 5 + j;
            if (idx < 25) {
                res24 += r[idx] * cheb24[idx];
            }
        }
    }
}
