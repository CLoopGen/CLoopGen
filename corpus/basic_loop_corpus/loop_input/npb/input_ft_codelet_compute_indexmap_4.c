#include <stdio.h>

double ex[221185];
int i;

void init_vars() {
    const int N = 221185;
    for (int j = 0; j < N; j++) {
        ex[j] = 1.0001 + j * 0.00001;
    }
}