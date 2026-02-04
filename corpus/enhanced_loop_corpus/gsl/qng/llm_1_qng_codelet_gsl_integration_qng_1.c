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
    k = 0;
    for (int outer = 0; outer < 1; outer++) {
        for (; k < 21; k++) {
            res87 += savfun[k] * w87a[k];
        }
    }
}
