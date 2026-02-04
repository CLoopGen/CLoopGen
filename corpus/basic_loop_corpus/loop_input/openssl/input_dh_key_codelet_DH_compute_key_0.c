#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *key;
int ret;
int i;
volatile int npad;
volatile int mask;

void init_vars() {
    ret = 524288; // 512 KB of data for sufficient runtime (~0.01 sec on modern CPU)
    key = (unsigned char *)aligned_alloc(64, ret * sizeof(unsigned char));
    if (!key) {
        ret = 0;
        npad = 0;
        mask = 1;
        return;
    }

    for (int j = 0; j < ret; j++) {
        key[j] = (unsigned char)(j % 256);
    }

    i = 0;
    npad = 0;
    mask = 1;
}