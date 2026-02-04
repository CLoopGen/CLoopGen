#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define N 1000

float a[N][N];
float b[N][N];
float c[N][N];

void init_vars() {
    srand(0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = (float)(rand()) / RAND_MAX;
            b[i][j] = (float)(rand()) / RAND_MAX;
            c[i][j] = 0.0F;
        }
    }
}