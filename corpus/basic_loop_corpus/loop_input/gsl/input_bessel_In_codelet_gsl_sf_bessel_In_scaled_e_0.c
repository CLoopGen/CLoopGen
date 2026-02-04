#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int n = 1000000;
double ax = 1.5;
double Ikp1 = 2.0;
double Ik = 1.0;
double Ikm1;
int k;

void init_vars() {
    Ikp1 = 2.0;
    Ik = 1.0;
    Ikm1 = 0.0;
    n = 1000000;
    ax = 1.5;
}