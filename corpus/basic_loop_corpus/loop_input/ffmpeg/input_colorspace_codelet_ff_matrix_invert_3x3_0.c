#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double out[3][3];
int i;
int j;
double det;

void init_vars() {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            out[i][j] = 1.0 + i * 3 + j;
        }
    }
    det = 2.5;
    i = 0;
    j = 0;
}