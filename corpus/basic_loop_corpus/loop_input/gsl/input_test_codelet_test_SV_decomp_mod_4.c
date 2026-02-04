#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double lower = 123.456;

static double a_data[67108864]; // ~512 MB of data to ensure loop runtime ~0.01 sec
double *a = a_data;

void init_vars() {
    i = 0;
    lower = 123.456;
    for (int j = 0; j < 67108864; j++) {
        a_data[j] = 0.0;
    }
}