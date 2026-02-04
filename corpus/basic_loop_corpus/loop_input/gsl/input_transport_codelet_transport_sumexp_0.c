#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int numexp = 1000;
int order = 1000;
double t = 1.0001;
double x = 0.999;
double rk = 1000.0;
double sumexp = 1.0;
int k;

void init_vars() {
    // No dynamic allocation needed; all variables are scalars
    // Values are already initialized at file scope
}