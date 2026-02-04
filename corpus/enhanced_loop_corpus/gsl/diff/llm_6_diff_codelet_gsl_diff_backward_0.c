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
for (k = 1; k < 4; k++) {
    double temp[3] = {0};
    for (i = 0; i < 3 - k; i++) {
        temp[i] = (d[i + 1] - d[i]) / (a[i + k] - a[i]);
    }
    for (i = 0; i < 3 - k; i++) {
        d[i] = temp[i];
    }
}
}
