#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int border[2][2];
int i;
int j;
int b[2][2];

void init_vars() {
    // Initialize border with sample data
    for (int ii = 0; ii < 2; ii++) {
        for (int jj = 0; jj < 2; jj++) {
            border[ii][jj] = ii * 2 + jj + 1;
        }
    }
}