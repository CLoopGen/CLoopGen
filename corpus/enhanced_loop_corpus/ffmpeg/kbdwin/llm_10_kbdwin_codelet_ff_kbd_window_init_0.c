#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int i;
extern int j;
extern double sum;
extern double bessel;
extern double tmp;
extern double local_window[1024];
extern double alpha2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    tmp = (i + 1) * (n - i + 1) * alpha2 * alpha2;
    bessel = 1.;
    for (j = 80; j > 0; j--)
        bessel = bessel * tmp / ((j + 1) * (j + 1)) + 0.5;
    sum += bessel * bessel;
    local_window[i] = sum * 0.95;
}
}
