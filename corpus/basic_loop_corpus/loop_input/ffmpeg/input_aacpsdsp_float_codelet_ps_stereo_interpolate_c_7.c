#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef float INTFLOAT;
typedef float UINTFLOAT;

#define DATA_SIZE_MB 64
#define ELEMENTS_PER_MB (1024 * 1024 / sizeof(float) / 2)
#define LEN (DATA_SIZE_MB * ELEMENTS_PER_MB)

INTFLOAT (*l)[2];
INTFLOAT (*r)[2];
int len = LEN;
INTFLOAT h0 = 1.0f;
INTFLOAT h1 = 1.0f;
INTFLOAT h2 = 0.5f;
INTFLOAT h3 = 0.5f;
UINTFLOAT hs0 = 0.001f;
UINTFLOAT hs1 = 0.001f;
UINTFLOAT hs2 = 0.001f;
UINTFLOAT hs3 = 0.001f;
int n;

void init_vars() {
    l = (INTFLOAT(*)[2])aligned_alloc(32, len * sizeof(INTFLOAT[2]));
    r = (INTFLOAT(*)[2])aligned_alloc(32, len * sizeof(INTFLOAT[2]));

    if (!l || !r) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < len; i++) {
        l[i][0] = (INTFLOAT)(i % 100) * 0.1f;
        l[i][1] = (INTFLOAT)((i + 10) % 100) * 0.1f;
        r[i][0] = (INTFLOAT)((i + 20) % 100) * 0.1f;
        r[i][1] = (INTFLOAT)((i + 30) % 100) * 0.1f;
    }
}