#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double temp[15];
double sum;

void init_vars() {
    sum = 0.0;
    for (int i = 0; i < 15; i++) {
        temp[i] = (double)(i + 1);
    }
}