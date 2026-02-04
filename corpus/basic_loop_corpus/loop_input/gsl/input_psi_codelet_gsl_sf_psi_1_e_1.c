#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

double x = 1.0;
int M = 10000000; // Adjusted to achieve ~0.01 sec runtime
double sum = 0.0;
int m = 0;

void init_vars() {
    x = 1.0;
    M = 10000000;
    sum = 0.0;
    m = 0;
}