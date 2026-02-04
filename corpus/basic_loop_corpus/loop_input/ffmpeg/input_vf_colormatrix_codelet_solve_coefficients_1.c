#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double cm[3][3];
double rgb[3][3];
double yuv[3][3];
int i;
int j;

void init_vars() {
    for (int ii = 0; ii < 3; ii++) {
        for (int jj = 0; jj < 3; jj++) {
            yuv[ii][jj] = (double)(ii * 3 + jj + 1);
            rgb[ii][jj] = (double)(ii * 3 + jj + 1) * 0.5;
            cm[ii][jj] = 0.0;
        }
    }
    i = 0;
    j = 0;
}