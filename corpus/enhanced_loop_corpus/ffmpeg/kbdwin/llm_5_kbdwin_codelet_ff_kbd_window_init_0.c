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
    tmp = i * (n - i) * alpha2;
    bessel = 1.;
    for (j = 50; j > 0; j--) {
        if (tmp > 1e-6) {
            bessel = bessel * tmp / (j * j) + 1;
        } else {
            bessel = 1.0;
            break;
        }
    }
    sum += bessel;
    local_window[i] = sum;
}
}
