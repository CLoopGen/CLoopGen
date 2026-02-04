#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int UInt32;
typedef int Int32;

UInt32 *fmap;
UInt32 *eclass;
Int32 lo;
Int32 hi;
Int32 i;
Int32 j;
Int32 tmp;
UInt32 ec_tmp;

void init_vars() {
    const Int32 data_size = 65536; 

    fmap = (UInt32*)malloc(data_size * sizeof(UInt32));
    eclass = (UInt32*)malloc(data_size * sizeof(UInt32));

    for (Int32 idx = 0; idx < data_size; idx++) {
        fmap[idx] = data_size - idx - 1;
        eclass[idx] = rand() % 1000;
    }

    lo = 100;
    hi = data_size - 1;
}