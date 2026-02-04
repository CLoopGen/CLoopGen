#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned char uchar;

int patlen = 1 << 20;
int skip2;
uchar *pat;
int i;
int lastpatchar;

void init_vars() {
    pat = (uchar *)malloc(patlen * sizeof(uchar));
    for (i = 0; i < patlen; ++i) {
        pat[i] = (uchar)(i % 256);
    }
    lastpatchar = pat[patlen - 2];
    skip2 = 0;
}