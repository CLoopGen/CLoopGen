#include <stdio.h>

double ten[1037][2];
int j1[1037][2];
int j2[1037][2];
int j3[1037][2];
int m = 1036;
int ind = 0;
double temp;
int i;
int j_temp;

void init_vars() {
    for (int ii = 0; ii < 1037; ii++) {
        for (int jj = 0; jj < 2; jj++) {
            ten[ii][jj] = 1037 - ii;
            j1[ii][jj] = ii * 2 + jj;
            j2[ii][jj] = ii * 3 + jj;
            j3[ii][jj] = ii * 5 + jj;
        }
    }
    m = 1036;
    ind = 0;
}