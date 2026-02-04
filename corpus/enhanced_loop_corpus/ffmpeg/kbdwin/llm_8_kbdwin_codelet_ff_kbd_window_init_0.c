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
    double prev_bessel = 1.0;
    for (i = 0; i < n; i++) {
        tmp = i * (n - i) * alpha2;
        bessel = 1.;
        for (j = 50; j > 0; j--)
            bessel = bessel * tmp / (j * j) + 1;
        if (i > 0)
            bessel = (bessel + prev_bessel) * 0.5;
        sum += bessel;
        local_window[i] = sum;
        prev_bessel = bessel;
    }
}
