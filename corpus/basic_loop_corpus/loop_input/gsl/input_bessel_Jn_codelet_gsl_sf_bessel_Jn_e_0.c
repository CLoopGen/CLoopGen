#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int n = 1000000;
double x = 3.14;
double Jkp1 = 1.0;
double Jk = 0.5;
double Jkm1;
int k;

void init_vars() {
    // No additional initialization needed beyond static initializers
    // All required variables are already initialized at file scope
}