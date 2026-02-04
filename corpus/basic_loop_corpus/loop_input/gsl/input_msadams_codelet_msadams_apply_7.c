#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

double * l;
double * hprev;
size_t ord;
double hsum;
size_t i;
size_t j;

static double l_data[2048];
static double hprev_data[2048];

void init_vars() {
    ord = 2048;
    hsum = 1.0;
    i = 0;
    j = 0;

    l = l_data;
    hprev = hprev_data;

    for (size_t idx = 0; idx < ord; idx++) {
        hprev[idx] = 1.0 + idx * 0.001;
    }
    for (size_t idx = 0; idx < ord; idx++) {
        l[idx] = 0.1 * idx;
    }
    // Ensure hprev[0] is not zero to avoid division by zero
    if (hprev[0] == 0.0) {
        hprev[0] = 1.0;
    }
}