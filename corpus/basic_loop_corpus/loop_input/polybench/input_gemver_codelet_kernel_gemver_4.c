#include <stdio.h>
#include <inttypes.h>

int n = 1000;
double alpha = 1.5;

double A[2000][2000];
double w[2000];
double x[2000];
int i;
int j;

void init_vars() {
    for (int i = 0; i < n; i++) {
        w[i] = 0.0;
        x[i] = (double)(i + 1);
        for (int j = 0; j < n; j++) {
            A[i][j] = (double)(i * n + j) / 1000.0;
        }
    }
}