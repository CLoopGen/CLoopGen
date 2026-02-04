#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef int int32;

int32 n = 65536;
int32 *gauscore;
int32 i;
int32 th = 1000;
int32 nc;
int32 *sl;

void init_vars() {
    gauscore = (int32*)malloc(n * sizeof(int32));
    sl = (int32*)malloc(n * sizeof(int32));
    nc = 0;
    srand(time(NULL));
    for (int j = 0; j < n; j++) {
        gauscore[j] = rand() % 2000;
    }
    th = 1000;
}