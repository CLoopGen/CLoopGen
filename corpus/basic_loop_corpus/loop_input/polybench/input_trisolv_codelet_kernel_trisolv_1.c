#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

int n = 2000;

double L[2000][2000];
double x[2000];
double b[2000];
int i;
int j;

void init_vars() {
    srand(time(NULL));

    for (int idx = 0; idx < n; idx++) {
        b[idx] = ((double)rand()) / RAND_MAX * 100.0;
        x[idx] = 0.0;
        for (int jdx = 0; jdx < n; jdx++) {
            if (idx == jdx) {
                L[idx][jdx] = 1.0 + ((double)rand()) / RAND_MAX * 10.0;
            } else if (jdx < idx) {
                L[idx][jdx] = ((double)rand()) / RAND_MAX * 10.0;
            }
        }
    }
}