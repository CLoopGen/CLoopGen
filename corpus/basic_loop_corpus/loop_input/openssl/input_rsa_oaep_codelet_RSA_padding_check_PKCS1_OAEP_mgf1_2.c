#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int i;
unsigned char *maskedseed;
unsigned char seed[64];
int mdlen;

void init_vars() {
    mdlen = 64;
    maskedseed = (unsigned char *)malloc(mdlen * sizeof(unsigned char));
    if (!maskedseed) {
        return;
    }
    for (int j = 0; j < mdlen; j++) {
        seed[j] = (unsigned char)(j & 0xFF);
        maskedseed[j] = (unsigned char)((j + 1) & 0xFF);
    }
}