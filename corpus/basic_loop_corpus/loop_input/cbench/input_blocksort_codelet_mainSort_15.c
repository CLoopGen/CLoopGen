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
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    block = (UChar*)calloc(data_size, sizeof(UChar));
    quadrant = (UInt16*)calloc(data_size, sizeof(UInt16));
    ftab = (UInt32*)calloc(65536, sizeof(UInt32)); // j is 16-bit index: 0 to 65535

    if (!block || !quadrant || !ftab) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize block with non-zero test pattern
    for (size_t idx = 0; idx < data_size; idx++) {
        block[idx] = (UChar)(idx % 251);
    }

    // Initialize ftab to zero (already done by calloc, but being explicit)
    memset(ftab, 0, 65536 * sizeof(UInt32));

    // Set loop bounds: i starts at data_size - 1 and decrements to 0
    i = (Int32)(data_size - 1);
    j = 0xABCDE; // Arbitrary initial value for j
}