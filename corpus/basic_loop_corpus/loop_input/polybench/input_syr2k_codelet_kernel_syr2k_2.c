#include <stdio.h>
#include <inttypes.h>

int n = 1000;
int m = 800;
double alpha = 1.5;
double beta = 2.0;
double C[1200][1200];
double A[1200][1000];
double B[1200][1000];
int i = 0;
int j = 0;
int k = 0;

void init_vars() {
    for (int ii = 0; ii < 1200; ++ii) {
        for (int jj = 0; jj < 1200; ++jj) {
            if (jj < 1000) {
                A[ii][jj] = (double)(ii + jj);
                B[ii][jj] = (double)(ii - jj);
            }
            if (jj < 1200) {
                C[ii][jj] = (double)(ii * jj % 100) / 10.0;
            }
        }
    }
}