#include <stdio.h>
#include <inttypes.h>

int n = 1000;

double x1[2000] = {0.0};

double y_1[2000] = {0.0};

double A[2000][2000] = {{0.0}};

int i = 0;
int j = 0;

void init_vars() {
    for (int idx = 0; idx < n; idx++) {
        x1[idx] = 1.0;
        y_1[idx] = 2.0;
        for (int jdx = 0; jdx < n; jdx++) {
            A[idx][jdx] = 1.0 / (idx + jdx + 1);
        }
    }
}