#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x_sum[10];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 20; k += 2) {
        x_sum[k % 10] = 0.0;
        if (k + 1 < 20) {
            x_sum[(k + 1) % 10] += 1.0;
        }
    }
}
