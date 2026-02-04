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
for (i = 0; i < n; i += 2) {
    tmp = i * (n - i) * alpha2;
    bessel = 1.;
    for (j = 30; j > 0; j--)
        bessel = bessel * tmp / (j * j * j) + 1.5;
    sum += bessel;
    local_window[i] = sum;
    if (i + 1 < n) {
        local_window[i + 1] = sum * 1.1;
    }
}
}
