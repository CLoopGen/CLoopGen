#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double w43a[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
double savfun[21] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0,
                     1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0, 2.1};
double res43 = 0.0;
int k = 0;

void init_vars() {
    for (int i = 0; i < 10; i++) {
        w43a[i] = (double)(i + 1) * 1.5;
        savfun[i] = (double)(i + 1) * 0.5;
    }
    res43 = 0.0;
}