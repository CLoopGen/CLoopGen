#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int INTFLOAT;
typedef unsigned int UINTFLOAT;

#define DATA_SIZE_MB 64
#define ELEMENTS_PER_MB (1024 * 1024 / sizeof(int) / 2)
#define LEN (DATA_SIZE_MB * ELEMENTS_PER_MB)

INTFLOAT (*l)[2];
INTFLOAT (*r)[2];
int len = LEN;
INTFLOAT h0 = 12345;
INTFLOAT h1 = 67890;
INTFLOAT h2 = 54321;
INTFLOAT h3 = 98765;
UINTFLOAT hs0 = 1000;
UINTFLOAT hs1 = 2000;
UINTFLOAT hs2 = 1500;
UINTFLOAT hs3 = 2500;
int n;

void init_vars() {
    l = (INTFLOAT(*)[2])calloc(len, sizeof(INTFLOAT[2]));
    r = (INTFLOAT(*)[2])calloc(len, sizeof(INTFLOAT[2]));

    for (int i = 0; i < len; i++) {
        l[i][0] = i & 0x7FFF;
        l[i][1] = (i + 100) & 0x7FFF;
        r[i][0] = (i + 200) & 0x7FFF;
        r[i][1] = (i + 300) & 0x7FFF;
    }
}