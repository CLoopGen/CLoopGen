#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
    n = 1 << 20; // 1 million elements, adjust for ~0.01 sec runtime
    n2 = n / 2;
    n4 = n / 4;

    out = (INTFLOAT*)aligned_alloc(32, sizeof(INTFLOAT) * n4);
    saved = (INTFLOAT*)aligned_alloc(32, sizeof(INTFLOAT) * (3 * n + n2 + n4));
    buf = (INTFLOAT*)aligned_alloc(32, sizeof(INTFLOAT) * n2);
    window = (INTFLOAT*)aligned_alloc(32, sizeof(INTFLOAT) * (4 * n));

    for (int j = 0; j < n4; j++) {
        out[j] = 0.0f;
    }

    for (int j = 0; j < 3 * n + n2 + n4; j++) {
        saved[j] = (INTFLOAT)(rand() % 100) / 10.0f;
    }

    for (int j = 0; j < n2; j++) {
        buf[j] = (INTFLOAT)(rand() % 100) / 10.0f;
    }

    for (int j = 0; j < 4 * n; j++) {
        window[j] = (INTFLOAT)(rand() % 100) / 50.0f;
    }
}