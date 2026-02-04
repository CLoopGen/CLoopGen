#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef float INTFLOAT;
typedef float UINTFLOAT;

#define DATA_SIZE_MB 64
#define ELEMENTS_PER_MB (1024 * 1024 / (2 * sizeof(INTFLOAT)))
#define TOTAL_ELEMENTS (DATA_SIZE_MB * ELEMENTS_PER_MB)

INTFLOAT (*l)[2];
INTFLOAT (*r)[2];
int len = TOTAL_ELEMENTS;
INTFLOAT h0 = 1.0f;
INTFLOAT h1 = 1.0f;
INTFLOAT h2 = 1.0f;
INTFLOAT h3 = 1.0f;
UINTFLOAT hs0 = 0.001f;
UINTFLOAT hs1 = 0.001f;
UINTFLOAT hs2 = 0.001f;
UINTFLOAT hs3 = 0.001f;
int n;

void init_vars() {
    l = (INTFLOAT(*)[2])calloc(TOTAL_ELEMENTS, sizeof(*l));
    r = (INTFLOAT(*)[2])calloc(TOTAL_ELEMENTS, sizeof(*r));

    if (!l || !r) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < TOTAL_ELEMENTS; i++) {
        l[i][0] = (INTFLOAT)(i % 100) * 0.1f;
        l[i][1] = (INTFLOAT)((i + 10) % 100) * 0.1f;
        r[i][0] = (INTFLOAT)((i + 20) % 100) * 0.1f;
        r[i][1] = (INTFLOAT)((i + 30) % 100) * 0.1f;
    }
}