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
int indices[1024];
for (i = 0; i < n; i++) {
    indices[i] = n - 1 - i;
}
for (i = 0; i < n; i++) {
    int idx = indices[i];
    tmp = idx * (n - idx) * alpha2;
    bessel = 1.;
    for (j = 50; j > 0; j--)
        bessel = bessel * tmp / (j * j) + 1;
    sum += bessel;
    local_window[idx] = sum;
}
}
