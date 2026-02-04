#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef float INTFLOAT;
typedef float UINTFLOAT;

INTFLOAT (*l)[2];
INTFLOAT (*r)[2];
int len;
INTFLOAT h00;
INTFLOAT h10;
INTFLOAT h01;
INTFLOAT h11;
INTFLOAT h02;
INTFLOAT h12;
INTFLOAT h03;
INTFLOAT h13;
UINTFLOAT hs00;
UINTFLOAT hs10;
UINTFLOAT hs01;
UINTFLOAT hs11;
UINTFLOAT hs02;
UINTFLOAT hs12;
UINTFLOAT hs03;
UINTFLOAT hs13;
int n;

void init_vars() {
    len = 65536; // Approximately 1MB of data per array (65536 * 2 * sizeof(float) ≈ 512KB), total ~1MB

    l = (INTFLOAT(*)[2])calloc(len, 2 * sizeof(INTFLOAT));
    r = (INTFLOAT(*)[2])calloc(len, 2 * sizeof(INTFLOAT));

    if (!l || !r) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < len; i++) {
        l[i][0] = (INTFLOAT)(i % 128) / 64.0f;
        l[i][1] = (INTFLOAT)((i + 1) % 128) / 64.0f;
        r[i][0] = (INTFLOAT)((i + 2) % 128) / 64.0f;
        r[i][1] = (INTFLOAT)((i + 3) % 128) / 64.0f;
    }

    h00 = 1.0f;
    h10 = 0.5f;
    h01 = 0.3f;
    h11 = 0.7f;
    h02 = 0.4f;
    h12 = 0.6f;
    h03 = 0.8f;
    h13 = 0.9f;

    hs00 = 0.0001f;
    hs10 = 0.0001f;
    hs01 = 0.0001f;
    hs11 = 0.0001f;
    hs02 = 0.0001f;
    hs12 = 0.0001f;
    hs03 = 0.0001f;
    hs13 = 0.0001f;

    n = 0;
}