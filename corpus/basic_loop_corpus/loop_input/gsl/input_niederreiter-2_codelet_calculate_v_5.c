#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int m = 10;
int maxv = (1 << 20);
int r, k;

int pb[10]; // m is 10, so pb has size m
int v[(1 << 20) + 10 + 1]; // maxv + m + 1 to safely access v[r + m] when r = maxv - m

void init_vars() {
    for (int i = 0; i < m; i++) {
        pb[i] = rand() % 2;
    }
    for (int i = 0; i < maxv + m + 1; i++) {
        v[i] = rand() % 2;
    }
}