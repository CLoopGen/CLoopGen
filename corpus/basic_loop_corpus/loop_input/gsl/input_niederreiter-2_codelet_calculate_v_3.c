#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int pb[51];
int ph[51];
int k;

void init_vars() {
    for (int i = 0; i < 51; i++) {
        pb[i] = rand();
    }
    for (int i = 0; i < 51; i++) {
        ph[i] = 0;
    }
    k = 0;
}