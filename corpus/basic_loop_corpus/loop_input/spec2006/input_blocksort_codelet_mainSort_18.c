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

#define DATA_SIZE (1 << 20) // 1MB

void init_vars() {
    ptr = (UInt32*)calloc(DATA_SIZE, sizeof(UInt32));
    block = (UChar*)malloc(DATA_SIZE * sizeof(UChar));
    ftab = (UInt32*)calloc(65536, sizeof(UInt32)); // 16-bit suffix → 65536 entries

    if (!ptr || !block || !ftab) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize block with pseudo-random data
    for (Int32 idx = 0; idx < DATA_SIZE; ++idx) {
        block[idx] = (UChar)(idx * 7919 % 256); // Arbitrary prime-based pattern
    }

    // Initialize ftab: each 16-bit value maps to a count of how many times it appears in block
    for (Int32 idx = 0; idx < DATA_SIZE - 1; ++idx) {
        UInt16 key = (block[idx] << 8) | block[idx + 1];
        ftab[key]++;
    }

    // Convert counts to cumulative offsets (from end)
    UInt32 sum = 0;
    for (Int32 idx = 0; idx < 65536; ++idx) {
        UInt32 temp = ftab[idx];
        ftab[idx] = sum;
        sum += temp;
    }

    // Set initial loop index i to last valid position >= 3
    i = DATA_SIZE - 1;
    j = 0;
    s = (block[i] << 8) | block[i-1]; // initial bigram
}