#include <stdio.h>

double ablock[5][5];
double avec[5];
double bvec[5];
int i;

void init_vars() {
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            ablock[row][col] = (double)(row * 5 + col + 1);
        }
    }
    for (int j = 0; j < 5; j++) {
        avec[j] = (double)(j + 1);
        bvec[j] = (double)(j * 10);
    }
    i = 0;
}