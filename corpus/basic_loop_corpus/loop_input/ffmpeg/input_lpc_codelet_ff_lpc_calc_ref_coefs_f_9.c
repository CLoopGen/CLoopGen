#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int order = 24000000;
int i;
double avg_err = 1.5;
double error[33];

void init_vars() {
    order = 32;
    avg_err = 0.0;
    for (i = 0; i < 33; i++) {
        error[i] = (double)(i * 7) / 100.0;
    }
}