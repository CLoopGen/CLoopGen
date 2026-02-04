#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
    len = 65536; // ~1MB of data per array (65536 * 2 * sizeof(float) ≈ 512KB per array)

    l = (INTFLOAT(*)[2])calloc(len, 2 * sizeof(INTFLOAT));
    r = (INTFLOAT(*)[2])calloc(len, 2 * sizeof(INTFLOAT));

    h00 = 1.0f;
    h10 = 0.5f;
    h01 = 0.8f;
    h11 = 0.3f;
    h02 = 0.7f;
    h12 = 0.4f;
    h03 = 0.9f;
    h13 = 0.6f;

    hs00 = 0.001f;
    hs10 = 0.0005f;
    hs01 = 0.0008f;
    hs11 = 0.0003f;
    hs02 = 0.0007f;
    hs12 = 0.0004f;
    hs03 = 0.0009f;
    hs13 = 0.0006f;

    for (n = 0; n < len; n++) {
        l[n][0] = (INTFLOAT)(n % 100) * 0.01f;
        l[n][1] = (INTFLOAT)((n + 1) % 100) * 0.01f;
        r[n][0] = (INTFLOAT)((n + 2) % 100) * 0.01f;
        r[n][1] = (INTFLOAT)((n + 3) % 100) * 0.01f;
    }

    n = 0;
}