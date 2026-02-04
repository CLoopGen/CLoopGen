#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int INTFLOAT;

INTFLOAT *out;
INTFLOAT *saved;
INTFLOAT *buf;
int i;
int n = 1 << 24; // ~67M elements total, adjust for ~0.01s runtime
int n2;
int n4;
INTFLOAT *window;

void init_vars() {
    n2 = n / 2;
    n4 = n / 4;

    out = (INTFLOAT*)aligned_alloc(32, sizeof(INTFLOAT) * (n2 - n4));
    saved = (INTFLOAT*)aligned_alloc(32, sizeof(INTFLOAT) * (4 * n + 2 * n2));
    buf = (INTFLOAT*)aligned_alloc(32, sizeof(INTFLOAT) * (n2));
    window = (INTFLOAT*)aligned_alloc(32, sizeof(INTFLOAT) * (4 * n));

    if (!out || !saved || !buf || !window) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < n2; j++) {
        buf[j] = rand() % 1000 - 500;
    }

    for (int j = 0; j < 4 * n + 2 * n2; j++) {
        saved[j] = rand() % 1000 - 500;
    }

    for (int j = 0; j < 4 * n; j++) {
        window[j] = rand() % 1000 - 500;
    }

    for (int j = 0; j < (n2 - n4); j++) {
        out[j] = 0;
    }
}