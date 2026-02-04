#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double t[50];
int n;

void init_vars() {
    t[0] = 1.0;
    for (int i = 1; i < 50; i++) {
        t[i] = 0.0;
    }
    n = 0;
}