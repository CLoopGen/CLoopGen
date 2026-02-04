#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double x2 = 1.5;
double gl0 = 1.0;
int64_t k;
double a[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};

void init_vars() {
    // No dynamic data requiring initialization beyond static definitions
    // All variables are defined and initialized at file scope
}