#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef unsigned int UInt32;
typedef int Int32;

UInt32 *fmap;
UInt32 *eclass;
UInt32 *bhtab;
Int32 i;
Int32 l;
Int32 r;
Int32 cc;
Int32 cc1;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB for reasonable runtime (~0.01s on modern CPU)

    fmap = (UInt32*)calloc(data_size, sizeof(UInt32));
    eclass = (UInt32*)calloc(data_size, sizeof(UInt32));
    bhtab = (UInt32*)calloc((data_size + 31) / 32, sizeof(UInt32));

    if (!fmap || !eclass || !bhtab) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        fmap[idx] = idx % (data_size / 4);
        eclass[idx] = (idx * 7919) % 1000; // Prime multiplier for pseudo-randomness
    }

    l = 0;
    r = data_size - 1;
    cc = -1;
}