#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double coeff[131072]; // 1MB of doubles: 131072 elements * 8 bytes = ~1MB
int ii;
double sum;

void init_vars() {
    for (int i = 0; i < 131072; ++i) {
        coeff[i] = (double)(i + 1);
    }
    sum = 12345.678;
}