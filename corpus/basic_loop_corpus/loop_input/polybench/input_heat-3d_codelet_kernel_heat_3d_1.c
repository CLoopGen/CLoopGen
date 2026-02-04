#include <stdio.h>
#include <inttypes.h>

int n = 100;
double A[120][120][120];
double B[120][120][120];
int t;
int i;
int j;
int k;

void init_vars() {
    for (int ii = 0; ii < 120; ++ii) {
        for (int jj = 0; jj < 120; ++jj) {
            for (int kk = 0; kk < 120; ++kk) {
                A[ii][jj][kk] = (double)(ii + jj + kk);
                B[ii][jj][kk] = 0.0;
            }
        }
    }
    t = 0;
    i = 0;
    j = 0;
    k = 0;
}