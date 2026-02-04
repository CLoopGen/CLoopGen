#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef unsigned int UInt32;
typedef int Int32;

#define DATA_SIZE (64 * 1024 * 1024)

UInt32 *fmap;
UInt32 *eclass;
UInt32 *bhtab;
Int32 i;
Int32 l;
Int32 r;
Int32 cc;
Int32 cc1;

void init_vars() {
    fmap = (UInt32*)calloc(DATA_SIZE, sizeof(UInt32));
    eclass = (UInt32*)calloc(DATA_SIZE, sizeof(UInt32));
    bhtab = (UInt32*)calloc((DATA_SIZE + 31) / 32, sizeof(UInt32));

    for (UInt32 idx = 0; idx < DATA_SIZE; idx++) {
        fmap[idx] = idx % (DATA_SIZE / 4);
        eclass[idx] = (idx % 7 == 0) ? (idx / 7) : ((idx - 1) / 7);
    }

    l = 0;
    r = DATA_SIZE - 1;
    cc = -1;
    cc1 = 0;
}