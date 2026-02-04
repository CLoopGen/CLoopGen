#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned char UChar;
typedef unsigned short UInt16;
typedef int Int32;

UChar *block;
UInt16 *quadrant;
Int32 nblock;
Int32 i;

void init_vars() {
    const Int32 total_size = 100 * 1024 * 1024; // 100 MB
    nblock = total_size / 2;

    block = (UChar*)calloc(total_size, sizeof(UChar));
    if (!block) exit(1);

    quadrant = (UInt16*)calloc(total_size, sizeof(UInt16));
    if (!quadrant) exit(1);

    for (Int32 j = 0; j < total_size; j++) {
        block[j] = (UChar)(j % 256);
    }
}