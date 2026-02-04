#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double temp[15];
double d1;

void init_vars() {
    d1 = 0.5;
    for (int i = 0; i < 15; i++) {
        temp[i] = (double)(i + 1) * 1.5;
    }
}