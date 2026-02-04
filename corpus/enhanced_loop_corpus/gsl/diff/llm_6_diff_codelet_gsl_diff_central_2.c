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
    double temp[4] = {0};
    for (k = 1; k < 5; k++) {
        for (i = 0; i < 4 - k; i++) {
            temp[i] = (d[i + 1] - d[i]) / (a[i + k] - a[i]);
        }
        for (i = 0; i < 4 - k; i++) {
            d[i] = temp[i];
        }
    }
}
