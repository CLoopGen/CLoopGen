#include <stdio.h>

double ablock[5][5];
double bblock[5][5];
double cblock[5][5];
int j;

void init_vars() {
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++) {
            ablock[i][k] = (double)(i * 5 + k + 1);
            bblock[i][k] = (double)(i * 5 + k + 1) * 0.5;
            cblock[i][k] = (double)(i * 5 + k + 1) * 2.0;
        }
    }
    j = 0;
}