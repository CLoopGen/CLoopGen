#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int k;
extern double a[4];
extern double d[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k < 5; k++) {
        double prev_d = d[0];
        for (i = 0; i < 4 - k; i++) {
            double current_diff = (d[i + 1] - prev_d) / (a[i + k] - a[i]);
            prev_d = d[i + 1];
            d[i] = current_diff;
        }
    }
}
