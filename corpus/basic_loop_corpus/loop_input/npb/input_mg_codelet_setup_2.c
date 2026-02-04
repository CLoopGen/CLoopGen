#include <stdio.h>

int nx[12];
int ny[12];
int nz[12];
int m1[12];
int m2[12];
int m3[12];
int lt;
int k;

void init_vars() {
    lt = 10; // Ensures k from 1 to lt (<=10) stays within bounds of arrays of size 12
    for (int i = 1; i <= lt; i++) {
        nx[i] = i * 3;
        ny[i] = i * 5;
        nz[i] = i * 7;
    }
}