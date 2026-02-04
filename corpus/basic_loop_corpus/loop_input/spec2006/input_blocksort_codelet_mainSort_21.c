#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned int UInt32;
typedef int Int32;

UInt32 *ftab;
Int32 i;
Int32 j;
Int32 runningOrder[256];
Int32 vv;
Int32 h;

void init_vars() {
    h = 1;
    i = 0;
    j = 0;
    vv = 0;

    for (int idx = 0; idx < 256; idx++) {
        runningOrder[idx] = idx;
    }

    const size_t ftab_size = (257 << 8);
    ftab = (UInt32*)calloc(ftab_size, sizeof(UInt32));

    if (!ftab) {
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < ftab_size; idx++) {
        ftab[idx] = (UInt32)(rand() % 100000);
    }

    for (size_t idx = 1; idx < ftab_size; idx++) {
        ftab[idx] += ftab[idx - 1];
    }
}