#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 50

double t[ARRAY_SIZE];
double x;
int n;

void init_vars() {
    x = 1.5;
    t[0] = 1.0;
    for (int i = 1; i < ARRAY_SIZE; i++) {
        t[i] = 0.0;
    }
    n = 0;
}