#include <stdio.h>
#include <inttypes.h>

int n = 1000;

double x2[2000];
double y_2[2000];
double A[2000][2000];
int i;
int j;

void init_vars() {
    for (int idx_i = 0; idx_i < 2000; idx_i++) {
        x2[idx_i] = 1.0 + idx_i * 0.1;
        y_2[idx_i] = 2.0 + idx_i * 0.2;
        for (int idx_j = 0; idx_j < 2000; idx_j++) {
            A[idx_j][idx_i] = (idx_i + idx_j) * 0.01;
        }
    }
    n = 1000;
}