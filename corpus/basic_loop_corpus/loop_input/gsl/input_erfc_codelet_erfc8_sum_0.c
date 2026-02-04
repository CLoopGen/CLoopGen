#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

double x;
double P[5];
double num;
int i;

void init_vars() {
    x = 2.0;
    num = 1.0;
    for (int j = 0; j < 5; ++j) {
        P[j] = j * j + 1;
    }
}