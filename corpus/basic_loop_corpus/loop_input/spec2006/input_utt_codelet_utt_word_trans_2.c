#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int int32;

int32 n_ci = 65536;
int32 *bs;
int32 *bv;
int32 p;

void init_vars() {
    bs = (int32*)malloc(n_ci * sizeof(int32));
    bv = (int32*)malloc(n_ci * sizeof(int32));
}