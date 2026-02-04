#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

double qq = 1.5;
double aa = 100.0;
double term = 0.1;
int ii;
int n1 = 20000000; // Chosen to achieve ~0.01 sec runtime

void init_vars() {
    qq = 1.5;
    aa = 100.0;
    term = 0.1;
    ii = 0;
    n1 = 20000000;
}