#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double t[20];
double sum;
int n;

void init_vars() {
    n = 0;
    sum = 0.0;
    for (int i = 0; i < 20; i++) {
        t[i] = 0.0;
    }
}