#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int count[27];
double chisq;
int i;

void init_vars() {
    for (int j = 0; j < 27; j++) {
        count[j] = 10000 + (j * 137) % 2000;
    }
    chisq = 0.0;
    i = 0;
}