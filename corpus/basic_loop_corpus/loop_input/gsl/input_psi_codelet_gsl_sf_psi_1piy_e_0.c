#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

double y = 3.14159;
int M = 10000000;  // Adjusted to achieve ~0.01 seconds runtime
double sum = 0.0;
int n;

void init_vars() {
    y = 3.14159;
    M = 10000000;
    sum = 0.0;
    n = 0;
}