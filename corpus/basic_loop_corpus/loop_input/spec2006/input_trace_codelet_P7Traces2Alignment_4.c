#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int mlen;
int alen;
int *inserts;
int *matmap;
int k;

void init_vars() {
    mlen = 10000000;  // 10 million elements for ~0.01 sec runtime
    alen = 100;

    inserts = (int*)malloc((mlen + 1) * sizeof(int));
    matmap = (int*)malloc((mlen + 1) * sizeof(int));

    for (int i = 1; i <= mlen; i++) {
        inserts[i] = i % 100;
        matmap[i] = 0;
    }
}