#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double w43a[10];
extern double savfun[21];
extern double res43;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    res43 = 0.0;
    for (k = 0; k < 10; k++) {
        if (w43a[k] > 0) {
            res43 += savfun[k] * w43a[k];
        }
    }
}
