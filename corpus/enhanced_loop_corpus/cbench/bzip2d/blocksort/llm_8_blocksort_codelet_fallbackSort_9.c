#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 nblock;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 2) {
        UInt32 index1 = nblock + 2 * i;
        UInt32 shift1 = index1 & 31;
        UInt32 word_index1 = index1 >> 5;
        bhtab[word_index1] |= (1U << shift1);

        UInt32 index2 = nblock + 2 * i + 1;
        UInt32 shift2 = index2 & 31;
        UInt32 word_index2 = index2 >> 5;
        bhtab[word_index2] &= ~(1U << shift2);
    }
}
