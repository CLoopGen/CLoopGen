#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int time_repeat = 10000000;
double *t = NULL;
int k = 0;

void init_vars() {
    t = (double*)calloc(time_repeat, sizeof(double));
}