#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int n1;
int n2;
int i;
int j;
int memcnt;
float dvalue;
float **w;
char *mem;

void init_vars() {
    n1 = 1024;
    n2 = 256;
    memcnt = 0;

    w = (float**)calloc(n1 + 1, sizeof(float*));
    if (!w) exit(1);
    for (int idx_i = 0; idx_i <= n1; idx_i++) {
        w[idx_i] = (float*)calloc(n2 + 1, sizeof(float));
        if (!w[idx_i]) exit(1);
        for (int idx_j = 0; idx_j <= n2; idx_j++) {
            w[idx_i][idx_j] = (float)(idx_i * (n2 + 1) + idx_j);
        }
    }

    size_t total_size = (size_t)(n1 + 1) * (n2 + 1) * sizeof(float);
    mem = (char*)malloc(total_size);
    if (!mem) exit(1);
}