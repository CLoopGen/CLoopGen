#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x_sum[10];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 10; k++) {
        if (k >= 0) {
            x_sum[k] = 0.;
        }
    }
}
