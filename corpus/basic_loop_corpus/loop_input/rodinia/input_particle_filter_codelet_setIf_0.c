#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int testValue;
int newValue;
int *array3D;
int *dimX;
int *dimY;
int *dimZ;
int x;
int y;
int z;

static int _dimX_storage = 64;
static int _dimY_storage = 64;
static int _dimZ_storage = 64;

void init_vars() {
    testValue = 42;
    newValue = 84;

    dimX = &_dimX_storage;
    dimY = &_dimY_storage;
    dimZ = &_dimZ_storage;

    size_t total_size = (size_t)(*dimX) * (*dimY) * (*dimZ);
    array3D = (int*)calloc(total_size, sizeof(int));
    if (!array3D) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        array3D[i] = (rand() % 100 == 0) ? testValue : rand() % 1000;
    }
}