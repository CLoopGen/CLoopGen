#include <stdio.h>
#include <inttypes.h>

int n = 1000;
double A[2000][2000];
int i;
int j;

void init_vars() {
    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            A[i][j] = 0.0;
        }
    }
    n = 1000;
}