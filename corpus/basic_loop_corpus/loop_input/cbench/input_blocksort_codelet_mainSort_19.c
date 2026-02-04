#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int UInt32;
typedef unsigned char UChar;
typedef int Int32;
typedef unsigned short UInt16;

UInt32 *ptr;
UChar *block;
UInt32 *ftab;
Int32 i;
Int32 j;
UInt16 s;

void init_vars() {
    const size_t BLOCK_SIZE = 1 << 20; // 1MB
    const size_t FTAB_SIZE = 1 << 16;   // 65536 entries for 16-bit s
    const size_t PTR_SIZE = BLOCK_SIZE;

    block = (UChar*)calloc(BLOCK_SIZE, sizeof(UChar));
    ptr = (UInt32*)malloc(PTR_SIZE * sizeof(UInt32));
    ftab = (UInt32*)malloc(FTAB_SIZE * sizeof(UInt32));

    if (!block || !ptr || !ftab) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < BLOCK_SIZE; idx++) {
        block[idx] = (UChar)(idx & 0xFF);
    }

    for (size_t idx = 0; idx < FTAB_SIZE; idx++) {
        ftab[idx] = (UInt32)(BLOCK_SIZE - (idx & 0xFFFF) % 1000);
    }

    for (size_t idx = 0; idx < PTR_SIZE; idx++) {
        ptr[idx] = (UInt32)(idx & 0x7FFFFFFF);
    }

    i = (Int32)(BLOCK_SIZE - 1);
    j = 0;
    s = 0x1234;
}