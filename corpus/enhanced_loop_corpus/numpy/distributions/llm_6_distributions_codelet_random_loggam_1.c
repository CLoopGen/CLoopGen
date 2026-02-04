#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x2;
extern double gl0;
extern int64_t k;
extern double a[10];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = gl0;
    for (k = 8; k >= 0; k--) {
        temp = temp * x2 + a[k];
    }
    gl0 = temp;
}
