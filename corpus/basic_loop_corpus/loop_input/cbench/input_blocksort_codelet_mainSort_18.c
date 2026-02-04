#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int UInt32;
typedef unsigned char UChar;
typedef int Int32;
typedef unsigned short UInt16;

#define DATA_SIZE (1 << 20) // 1MB

UInt32 *ptr;
UChar *block;
UInt32 *ftab;
Int32 i;
Int32 j;
UInt16 s;

void init_vars() {
    ptr = (UInt32*)calloc(DATA_SIZE, sizeof(UInt32));
    block = (UChar*)malloc(DATA_SIZE * sizeof(UChar));
    ftab = (UInt32*)calloc(65536, sizeof(UInt32)); // 16-bit table: 2^16 entries

    // Initialize block with non-zero data to avoid degenerate cases
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        block[idx] = (UChar)(idx & 0xFF);
    }

    // Initialize ftab: each entry points into valid range of ptr
    for (int idx = 0; idx < 65536; ++idx) {
        ftab[idx] = DATA_SIZE - 1;
    }

    // Set initial value of i to largest multiple of 4 <= DATA_SIZE-1, and >=3
    i = (DATA_SIZE - 1) & ~3;
    if (i < 3) i = 3;

    j = 0;
    s = 0;
}