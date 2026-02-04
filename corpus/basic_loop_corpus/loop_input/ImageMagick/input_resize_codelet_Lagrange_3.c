#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double x = 1.5;
double value;
ssize_t i;
ssize_t n = 1000000;
ssize_t order = 1000000;

void init_vars() {
    x = 1.5;
    value = 1.0;
    i = 0;
    n = 1000000;
    order = 1000000;
}