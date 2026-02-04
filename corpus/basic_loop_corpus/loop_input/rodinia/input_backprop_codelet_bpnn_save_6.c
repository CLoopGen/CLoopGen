#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

int n2;
int n3;
int i;
int j;
int memcnt;
float dvalue;
float **w;
char *mem;

void init_vars() {
    n2 = 400;
    n3 = 512;
    memcnt = 0;

    w = (float**)calloc(n2 + 1, sizeof(float*));
    if (!w) exit(1);

    for (int idx = 0; idx <= n2; idx++) {
        w[idx] = (float*)malloc((n3 + 1) * sizeof(float));
        if (!w[idx]) exit(1);
        for (int jdx = 0; jdx <= n3; jdx++) {
            w[idx][jdx] = 1.0f / ((idx + jdx + 1) * 0.5f);
        }
    }

    size_t total_size = (size_t)(n2 + 1) * (n3 + 1) * sizeof(float);
    mem = (char*)malloc(total_size);
    if (!mem) exit(1);
}