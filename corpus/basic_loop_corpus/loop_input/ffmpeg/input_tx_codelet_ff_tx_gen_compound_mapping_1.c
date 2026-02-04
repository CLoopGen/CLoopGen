#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *in_map;
int *out_map;
int n;
int m;
int len;
int m_inv;
int n_inv;
int mdct;

void init_vars() {
    n = 1024;
    m = 1024;
    len = n * m;
    mdct = 0;
    m_inv = 1;
    n_inv = 1;

    in_map = (int*)aligned_alloc(32, len * sizeof(int));
    out_map = (int*)aligned_alloc(32, len * sizeof(int));

    for (int i = 0; i < len; i++) {
        in_map[i] = 0;
        out_map[i] = 0;
    }
}