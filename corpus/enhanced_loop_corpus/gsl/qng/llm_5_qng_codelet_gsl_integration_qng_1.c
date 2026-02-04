#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double w87a[21];
extern double savfun[21];
extern double res87;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    res87 = 0.0;
    for (k = 0; k < 21; k += 3) {
        res87 += savfun[k] * w87a[k];
        if (k + 1 < 21) {
            res87 += savfun[k + 1] * w87a[k + 1];
        }
        if (k + 2 < 21) {
            res87 += savfun[k + 2] * w87a[k + 2];
        }
    }
}
