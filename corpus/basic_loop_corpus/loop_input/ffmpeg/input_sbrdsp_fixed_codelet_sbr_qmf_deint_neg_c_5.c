#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *v;
int *src;
int i;

static int v_buf[64];
static int src_buf[64];

void init_vars() {
    v = v_buf;
    src = src_buf;

    for (int j = 0; j < 64; j++) {
        src[j] = rand() % 1000;
    }

    for (int j = 0; j < 64; j++) {
        v[j] = 0;
    }

    i = 0;
}