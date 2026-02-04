#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int *lib1;
int k;
int libs[241];
int mse[400];

void init_vars() {
    for (int i = 0; i < 241; i++) {
        libs[i] = i % 400;
    }
    for (int i = 0; i < 400; i++) {
        mse[i] = 0;
    }
    lib1 = (int*)malloc(sizeof(int));
    *lib1 = 241;
}