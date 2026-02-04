#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int INTFLOAT;

INTFLOAT *out;
INTFLOAT *saved;
INTFLOAT *buf;
int i;
int n;
int n2;
int n4;
INTFLOAT *window;

void init_vars() {
    n = 16384;
    n2 = n / 2;
    n4 = n / 4;

    size_t out_size = (n2 + n4 + n4) * sizeof(INTFLOAT);
    size_t saved_size = (n + n2 + n4) * sizeof(INTFLOAT);
    size_t buf_size = (n2 + n4) * sizeof(INTFLOAT);
    size_t window_size = (3 * n - n4 + n4) * sizeof(INTFLOAT);

    out = (INTFLOAT*)calloc(out_size, 1);
    saved = (INTFLOAT*)calloc(saved_size, 1);
    buf = (INTFLOAT*)calloc(buf_size, 1);
    window = (INTFLOAT*)calloc(window_size, 1);

    for (int j = 0; j < n2 + n4; j++) {
        buf[j] = rand() % 1000 - 500;
    }

    for (int j = 0; j < n + n2 + n4; j++) {
        saved[j] = rand() % 1000 - 500;
    }

    for (int j = 0; j < 3 * n; j++) {
        window[j] = rand() % 1000 - 500;
    }
}