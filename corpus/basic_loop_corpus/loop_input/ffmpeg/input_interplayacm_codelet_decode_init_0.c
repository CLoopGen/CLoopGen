#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int mul_3x3[27];
int x1;
int x2;
int x3;

void init_vars() {
    // Initialize all variables to zero
    for (int i = 0; i < 27; i++) {
        mul_3x3[i] = 0;
    }
    x1 = 0;
    x2 = 0;
    x3 = 0;
}