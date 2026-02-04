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
    // Variant 1: Strided memory access with stride of 2 (backward traversal with step)
    // Arrays accessed with a fixed stride instead of consecutive indices
    for (; i >= 0; i -= 2) {
        s = (s >> 8) | (block[i] << 8);
        j = ftab[s] - 1;
        ftab[s] = j;
        ptr[j] = i;

        // Handle next element in stride if available
        if (i - 1 >= 0) {
            UInt16 s2 = (s >> 8) | (block[i - 1] << 8);
            Int32 j2 = ftab[s2] - 1;
            ftab[s2] = j2;
            ptr[j2] = i - 1;
        }
    }
}
