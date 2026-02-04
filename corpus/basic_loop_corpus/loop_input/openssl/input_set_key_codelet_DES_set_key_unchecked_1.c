#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned int DES_LONG;

DES_LONG des_skb[8][64];
int shifts2[16];
DES_LONG c;
DES_LONG d;
DES_LONG t;
DES_LONG s;
DES_LONG t2;
DES_LONG *k;
int i;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 64; j++) {
            des_skb[i][j] = (DES_LONG)(i * 64 + j);
        }
    }
    for (int i = 0; i < 16; i++) {
        shifts2[i] = (i % 3 == 0) ? 0 : 1;
    }
    c = 0x01234567;
    d = 0x89ABCDEF;
    k = (DES_LONG*)malloc(32 * sizeof(DES_LONG));
}