#include <stdio.h>
#include <stdlib.h>

#include <inttypes.h>

typedef unsigned int uint32;
typedef int int32;
typedef int32 tsize_t;
typedef uint32 tstrip_t;

uint32 bytecount;
uint32 offset;
tsize_t stripbytes;
tstrip_t strip;
tstrip_t nstrips;
uint32 *newcounts;
uint32 *newoffsets;

void init_vars() {
    nstrips = 65536;
    stripbytes = 4096;
    bytecount = nstrips * stripbytes;
    offset = 0;

    uint32 *counts_mem = (uint32*)calloc(nstrips, sizeof(uint32));
    uint32 *offsets_mem = (uint32*)calloc(nstrips, sizeof(uint32));

    newcounts = counts_mem;
    newoffsets = offsets_mem;
}