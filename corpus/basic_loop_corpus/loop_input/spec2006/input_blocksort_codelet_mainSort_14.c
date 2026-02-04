#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned char UChar;
typedef unsigned short UInt16;
typedef unsigned int UInt32;
typedef int Int32;

UChar *block;
UInt16 *quadrant;
UInt32 *ftab;
Int32 i;
Int32 j;

void init_vars() {
    const UInt32 data_size = 1 << 20; // 1MB of input data

    block = (UChar*)calloc(data_size, sizeof(UChar));
    quadrant = (UInt16*)calloc(data_size, sizeof(UInt16));
    ftab = (UInt32*)calloc(1 << 16, sizeof(UInt32)); // 64k entries for 16-bit j index

    if (!block || !quadrant || !ftab) {
        exit(1);
    }

    for (UInt32 idx = 0; idx < data_size; idx++) {
        block[idx] = (UChar)(idx * 71 % 251); // Populate with non-zero pseudo-random pattern
    }

    i = data_size - 1;
    j = 0x1234;
}