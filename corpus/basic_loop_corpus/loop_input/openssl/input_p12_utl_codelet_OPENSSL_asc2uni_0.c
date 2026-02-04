#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *asc;
int ulen;
int i;
unsigned char *unitmp;

void init_vars() {
    ulen = 512 * 1024;  // 512KB of data, ensures ~0.01 sec runtime on modern CPUs
    asc = (char *)malloc(ulen);
    unitmp = (unsigned char *)malloc(ulen);

    if (!asc || !unitmp) {
        exit(1);
    }

    for (int j = 0; j < ulen; ++j) {
        asc[j] = (char)(j & 0xFF);
    }

    memset(unitmp, 0, ulen);
}