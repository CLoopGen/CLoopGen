#include <stdio.h>
#include <inttypes.h>

int nr = 100;
int nq = 140;
int np = 160;
double A[150][140][160];
double C4[160][160];
double sum[160];
int r;
int q;
int p;
int s;

void init_vars() {
    for (int i = 0; i < 150; i++)
        for (int j = 0; j < 140; j++)
            for (int k = 0; k < 160; k++)
                A[i][j][k] = (double)(i + j + k) / 100.0;

    for (int i = 0; i < 160; i++)
        for (int j = 0; j < 160; j++)
            C4[i][j] = (double)(i * j) / 200.0;

    for (int i = 0; i < 160; i++)
        sum[i] = 0.0;
}