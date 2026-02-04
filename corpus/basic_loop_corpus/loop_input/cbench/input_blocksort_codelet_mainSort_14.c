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
    const size_t data_size = 64 * 1024 * 1024; // ~64MB for sufficient runtime (~0.01s on modern CPU)

    block = (UChar*)calloc(data_size, sizeof(UChar));
    quadrant = (UInt16*)calloc(data_size, sizeof(UInt16));
    ftab = (UInt32*)calloc(65536, sizeof(UInt32)); // 16-bit value range: 0-65535

    if (!block || !quadrant || !ftab) {
        exit(1);
    }

    // Initialize block with non-zero data to affect 'j' computation
    for (size_t idx = 0; idx < data_size; ++idx) {
        block[idx] = (UChar)(idx & 0xFF);
    }

    // Set loop index i to the largest multiple of 4 <= data_size - 1
    i = (data_size - 1) & ~3;

    // Initialize j with a predictable value
    j = ((UInt16)block[i]) << 8;
}