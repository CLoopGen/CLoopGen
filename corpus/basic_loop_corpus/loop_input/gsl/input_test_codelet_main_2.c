#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double t[50];
double x;
int n;

void init_vars() {
    x = 2.5;
    t[0] = 1.0;
    for (int i = 1; i < 50; i++) {
        t[i] = 0.0;
    }
    n = 0;
}