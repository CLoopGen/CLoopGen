#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef float INTFLOAT;

INTFLOAT *out;
INTFLOAT *saved;
INTFLOAT *buf;
int i;
int n;
int n2;
int n4;
INTFLOAT *window;

static INTFLOAT *alloc_aligned_float(size_t count) {
    void *ptr;
    if (posix_memalign(&ptr, 32, count * sizeof(INTFLOAT)) != 0) {
        return NULL;
    }
    return (INTFLOAT*)ptr;
}

void init_vars() {
    n = 1 << 20; // 1 million elements per segment
    n2 = n / 2;
    n4 = n / 4;

    buf = alloc_aligned_float(n2);
    saved = alloc_aligned_float(3 * n);
    out = alloc_aligned_float(n + n4);
    window = alloc_aligned_float(n2 + 3 * n);

    if (!buf || !saved || !out || !window) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < n2; i++) {
        buf[i] = 1.0f;
    }

    for (int i = 0; i < 3 * n; i++) {
        saved[i] = 1.0f;
    }

    for (int i = 0; i < n + n4; i++) {
        out[i] = 0.0f;
    }

    for (int i = 0; i < n2 + 3 * n; i++) {
        window[i] = 1.0f;
    }

    i = 0;
}