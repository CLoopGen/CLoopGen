#include <stdio.h>
#include <inttypes.h>

int np = 128;
double C4[160][160];
int i;
int j;

void init_vars() {
    np = 128;
    for (int ii = 0; ii < 160; ii++) {
        for (int jj = 0; jj < 160; jj++) {
            C4[ii][jj] = 0.0;
        }
    }
}