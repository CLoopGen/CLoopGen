#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float isf[20];
int i;

void init_vars() {
    for (int j = 0; j < 20; j++) {
        isf[j] = 1.0f;
    }
    i = 0;
}