#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int UInt32;
typedef int Int32;

UInt32 *bhtab;
Int32 nblock;
Int32 i;

void init_vars() {
    const Int32 data_size = 1 << 24; // ~16.7 million elements, roughly 64 MB for bhtab
    bhtab = (UInt32*)calloc(data_size, sizeof(UInt32));
    if (!bhtab) {
        exit(1);
    }
    nblock = 1024; // Ensures safe indexing with offset from 2*i and 2*i+1 up to i=31
}

__attribute__((destructor))
static void cleanup() {
    free(bhtab);
}