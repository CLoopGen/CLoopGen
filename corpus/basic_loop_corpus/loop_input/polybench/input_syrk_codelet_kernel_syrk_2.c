#include <stdio.h>
#include <inttypes.h>

int n = 1000;
int m = 800;
double alpha = 1.5;
double beta = 0.8;

double C[1200][1200];
double A[1200][1000];

int i = 0;
int j = 0;
int k = 0;

void init_vars() {
    for (int ii = 0; ii < 1200; ++ii) {
        for (int jj = 0; jj < 1200; ++jj) {
            C[ii][jj] = (double)(ii + jj) / 100.0;
        }
    }
    for (int ii = 0; ii < 1200; ++ii) {
        for (int kk = 0; kk < 1000; ++kk) {
            A[ii][kk] = (double)(ii - kk) / 50.0;
        }
    }
}