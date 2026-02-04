#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double dist[36];
double dsum[36];
int i;

void init_vars() {
    for (int j = 0; j < 36; j++) {
        dist[j] = (double)(j + 1) * 0.5;
        dsum[j] = 0.0;
    }
    i = 0;
}