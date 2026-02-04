#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int mulcost;
int reflcost;
int n;
int *A;
int i;
int j;
int k;
int changed;

void init_vars() {
    mulcost = 5;
    reflcost = 10;
    n = 8192;
    A = (int*)calloc(n, sizeof(int));
    if (!A) {
        exit(1);
    }
    for (int idx = 0; idx < n; ++idx) {
        A[idx] = (idx == 0) ? 0 : 1000000;
    }
    changed = 0;
    i = 0;
    j = 0;
    k = 0;
}