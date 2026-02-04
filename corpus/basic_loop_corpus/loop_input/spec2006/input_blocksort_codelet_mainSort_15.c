#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
    const UInt32 data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    block = (UChar*)malloc(data_size * sizeof(UChar));
    quadrant = (UInt16*)malloc(data_size * sizeof(UInt16));
    ftab = (UInt32*)calloc(65536, sizeof(UInt32)); // j is 16-bit index: 0-65535

    if (!block || !quadrant || !ftab) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (UInt32 idx = 0; idx < data_size; idx++) {
        block[idx] = (UChar)(idx & 0xFF);
    }

    for (UInt32 idx = 0; idx < data_size; idx++) {
        quadrant[idx] = 0;
    }

    i = data_size - 1;
    j = 0xABCDEF00; // Initial value with upper bits set
}