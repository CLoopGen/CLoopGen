#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[20];
extern double sum;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < 20; n++) {
    double np1 = (n + 1.) * (n + 1.);
    double np2 = (n + 2.) * (n + 2.);
    t[n] = 1. / np1 + 1. / np2;
    sum += t[n];
}
}
