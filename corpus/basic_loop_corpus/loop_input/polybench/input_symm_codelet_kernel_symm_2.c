#include <stdio.h>
#include <inttypes.h>

int m = 1000;
int n = 1200;
double alpha = 1.5;
double beta = 0.8;

double C[1000][1200];
double A[1000][1000];
double B[1000][1200];

int i = 0;
int j = 0;
int k = 0;
double temp2 = 0.0;

void init_vars() {
    for (int ii = 0; ii < 1000; ii++) {
        for (int jj = 0; jj < 1200; jj++) {
            C[ii][jj] = (ii + jj) * 0.001;
            if (jj < 1000) {
                A[ii][jj] = (ii - jj) * 0.002;
            }
            B[ii][jj] = (ii * jj % 17) * 0.01;
        }
    }
}