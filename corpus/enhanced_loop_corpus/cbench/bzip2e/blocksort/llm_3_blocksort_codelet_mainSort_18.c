#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef unsigned char UChar;

typedef int Int32;

typedef unsigned short UInt16;

extern UInt32 *ptr;
extern UChar *block;
extern UInt32 *ftab;
extern Int32 i;
extern Int32 j;
extern UInt16 s;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via a fixed offset table (micro-unrolling with indirect indexing)
    // Simulates non-linear access using a small lookup table for offsets, creating irregular but deterministic access
    static const Int32 offsets[4] = {0, 2, 1, 3}; // Reorders access: i, i-2, i-1, i-3
    for (; i >= 3; i -= 4) {
        // Access block[i - offsets[0]] = block[i]
        s = (s >> 8) | (block[i - offsets[0]] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i - offsets[0];

        // Access block[i - offsets[1]] = block[i - 2]
        s = (s >> 8) | (block[i - offsets[1]] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i - offsets[1];

        // Access block[i - offsets[2]] = block[i - 1]
        s = (s >> 8) | (block[i - offsets[2]] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i - offsets[2];

        // Access block[i - offsets[3]] = block[i - 3]
        s = (s >> 8) | (block[i - offsets[3]] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i - offsets[3];
    }
}
