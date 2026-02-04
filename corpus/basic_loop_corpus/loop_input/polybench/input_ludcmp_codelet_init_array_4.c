#include <stdio.h>
#include <inttypes.h>

int n = 1000;

double A[2000][2000];

int r;
int s;

double (*B)[2000][2000] = (double (*)[2000][2000])&A;

void init_vars() {
    n = 1000;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = (double)(i * n + j);
        }
    }
}