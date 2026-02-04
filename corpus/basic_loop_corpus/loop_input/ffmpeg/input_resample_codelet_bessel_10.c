#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double x;
double v;
double lastv;
double t;
int i;

void init_vars() {
    x = 2.5;
    v = 0.0;
    lastv = -1.0;
    t = 1.0;
    i = 0;
}