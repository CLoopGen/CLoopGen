#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double c[262144]; // 2MB array to target ~0.01 sec runtime
unsigned int n = 262144;
double x = 1.5;
unsigned int i;
double y;

void init_vars() {
    for (unsigned int j = 0; j < n; j++) {
        c[j] = (double)(j % 12345) * 0.001;
    }
    x = 1.5;
    y = 0.5;
    i = 0;
    n = 262144; // ensure valid bounds
}