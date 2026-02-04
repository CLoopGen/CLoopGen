#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 i;
extern Int32 nBhtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate potential WAW and WAR dependencies by writing non-overlapping sections
    // Assume nBhtab is even for simplicity; no functional change, but access pattern changed
    Int32 step = 2;
    // First pass: even indices
    for (i = 0; i < nBhtab; i += step)
        bhtab[i] = 0;
    // Second pass: odd indices – no write-write or write-read conflicts with first pass
    for (i = 1; i < nBhtab; i += step)
        bhtab[i] = 0;
}
