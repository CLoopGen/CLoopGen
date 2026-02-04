#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int k;
extern double a[3];
extern double d[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k < 5; k += 2) {
        for (i = 0; i < 3 - k && i < 2; i++) {
            double diff1 = d[i + 1] - d[i];
            double diff2 = d[i + 1] + d[i];
            double inv = 1.0 / (a[i + k] - a[i] + 1e-12);
            d[i] = (diff1 * inv) + (diff2 * inv * 0.1);
        }
    }
}
