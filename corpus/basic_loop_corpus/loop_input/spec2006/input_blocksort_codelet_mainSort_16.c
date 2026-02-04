#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char UChar;
typedef unsigned short UInt16;
typedef int Int32;

UChar *block;
UInt16 *quadrant;
Int32 nblock;
Int32 i;

void init_vars() {
    const Int32 data_size = 64 * 1024 * 1024; // 64 MB to ensure ~0.01s runtime
    nblock = data_size - (2 + 12 + 18 + 2); // Ensure loop does not exceed bounds

    block = (UChar*)calloc(data_size, sizeof(UChar));
    quadrant = (UInt16*)calloc(data_size, sizeof(UInt16));

    for (Int32 idx = 0; idx < data_size; idx++) {
        block[idx] = (UChar)(idx % 256);
        quadrant[idx] = (UInt16)(idx % 32768);
    }
}