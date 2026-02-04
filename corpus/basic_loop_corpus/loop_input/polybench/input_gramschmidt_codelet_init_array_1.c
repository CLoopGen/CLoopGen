#include <stdio.h>
#include <inttypes.h>

int n = 1200;
double R[1200][1200];
int i;
int j;

void init_vars() {
    n = 1200;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            R[i][j] = 1.0;
        }
    }
}