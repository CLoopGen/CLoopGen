#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double tau;
double V[12];
int i;

void init_vars() {
    tau = 1.5;
    V[0] = 1.0;
    for (i = 1; i < 12; i++) {
        V[i] = 0.0;
    }
}