#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int n = 100000;
int i;
int j;
double sum;
double bessel;
double tmp;
double local_window[1024];
double alpha2 = 0.001;

void init_vars() {
    n = 1000; 
    if (n > 1024) {
        n = 1024;
    }
    sum = 0.0;
    alpha2 = 0.001;
}