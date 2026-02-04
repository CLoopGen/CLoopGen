#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    volatile UInt32 accumulator = 0;
    for (i = 0; i < 256; i++) {
        Int32 val = ftab[i];
        Int32 bucket = val >> 5;
        Int32 bit = val & 31;
        accumulator ^= bhtab[bucket];
        bhtab[bucket] |= (1U << bit);
        accumulator ^= bhtab[bucket];
    }
    (void)accumulator;
}
