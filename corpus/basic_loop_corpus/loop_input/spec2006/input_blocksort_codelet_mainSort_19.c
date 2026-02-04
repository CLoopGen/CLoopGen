#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

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
    const size_t BLOCK_SIZE = 16777216; // 16MB to ensure ~0.01s runtime

    block = (UChar*)malloc(BLOCK_SIZE);
    ptr = (UInt32*)malloc(BLOCK_SIZE * sizeof(UInt32));
    ftab = (UInt32*)calloc(65536, sizeof(UInt32)); // 2^16 entries for 16-bit s

    if (!block || !ptr || !ftab) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize block with non-zero data to affect s meaningfully
    for (size_t k = 0; k < BLOCK_SIZE; k++) {
        block[k] = (UChar)(k & 0xFF);
    }

    // Initialize ftab: each entry points near end of ptr array
    for (int k = 0; k < 65536; k++) {
        ftab[k] = (UInt32)(BLOCK_SIZE - 1);
    }

    // Initialize loop control variables
    i = (Int32)(BLOCK_SIZE - 1); // Start from last valid index
    j = 0;
    s = 0;
}