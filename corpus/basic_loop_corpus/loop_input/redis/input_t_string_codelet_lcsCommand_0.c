#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef char *sds;

sds a;
sds b;
uint32_t alen;
uint32_t blen;
uint32_t *lcs;

void init_vars() {
    alen = 1000;
    blen = 1000;

    a = (sds)malloc(alen + 1);
    b = (sds)malloc(blen + 1);

    for (uint32_t i = 0; i < alen; i++) {
        a[i] = "ACGT"[i % 4];
    }
    for (uint32_t i = 0; i < blen; i++) {
        b[i] = "TGCA"[i % 4];
    }
    a[alen] = '\0';
    b[blen] = '\0';

    lcs = (uint32_t *)calloc((alen + 1) * (blen + 1), sizeof(uint32_t));
}