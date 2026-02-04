#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int IszX = 100;
int IszY = 100;
int Nfr = 25;
int *I;
int *newMatrix;
int x;
int y;
int k;

void init_vars() {
    size_t total_size = (size_t)IszX * IszY * Nfr * sizeof(int);
    I = (int*)calloc(total_size, 1);
    if (!I) {
        exit(1);
    }
    newMatrix = (int*)malloc(total_size);
    if (!newMatrix) {
        free(I);
        exit(1);
    }

    for (size_t i = 0; i < total_size / sizeof(int); i++) {
        newMatrix[i] = rand() % 1000;
    }
}