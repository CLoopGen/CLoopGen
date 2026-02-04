#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <stdint.h>

typedef float INTFLOAT;

INTFLOAT *out;
INTFLOAT *saved;
INTFLOAT *buf;
int i;
int n;
int n2;
int n4;
INTFLOAT *window;

void init_vars() {
    n = 1 << 18; // 256K elements, adjust for ~0.01 sec runtime
    n2 = n / 2;
    n4 = n / 4;

    out = (INTFLOAT*)aligned_alloc(32, sizeof(INTFLOAT) * n * 2);
    saved = (INTFLOAT*)aligned_alloc(32, sizeof(INTFLOAT) * (n + n2 + n4));
    buf = (INTFLOAT*)aligned_alloc(32, sizeof(INTFLOAT) * (n2 + n4));
    window = (INTFLOAT*)aligned_alloc(32, sizeof(INTFLOAT) * (3 * n));

    for (int idx = 0; idx < n2 + n4; idx++) {
        buf[idx] = (INTFLOAT)(rand() % 1000) / 1000.0f;
    }

    for (int idx = 0; idx < n2; idx++) {
        saved[idx] = (INTFLOAT)(rand() % 1000) / 1000.0f;
    }
    for (int idx = 0; idx < n4; idx++) {
        saved[n + n2 + idx] = (INTFLOAT)(rand() % 1000) / 1000.0f;
    }

    for (int idx = 0; idx < 3 * n; idx++) {
        window[idx] = (INTFLOAT)(rand() % 1000) / 1000.0f;
    }

    for (int idx = 0; idx < n * 2; idx++) {
        out[idx] = 0.0f;
    }
}