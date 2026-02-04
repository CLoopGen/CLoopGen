#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int n;
int k;
double y;
double k_term;
double sum1;

void init_vars() {
    n = 20000000;  
    y = 2.0;
    k_term = 1.0;
    sum1 = 0.0;
}