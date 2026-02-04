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
    for (k = 0; k < 3; k++) {
        for (i = 0; i < 2 - k; i++) {
            d[i] = (d[i + 2] - d[i]) / (a[i + k + 1] - a[i] + 1e-9);
        }
    }
}
