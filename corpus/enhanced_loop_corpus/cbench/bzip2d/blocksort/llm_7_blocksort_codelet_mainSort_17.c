#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Introduce additional WAW and WAR dependencies via temporary array to simulate write conflicts
    // Uses a local buffer to accumulate values first (breaking direct loop-carried RAW), then writes back
    // This creates a two-phase update: read-modify all, then write all — reversing the original order
    // Increases memory usage but changes data dependency pattern

    UInt32 *temp = (UInt32*)__builtin_alloca(65537 * sizeof(UInt32));
    temp[0] = ftab[0];

    for (i = 1; i <= 65536; i++) {
        temp[i] = temp[i - 1] + ftab[i];  // decoupled accumulation
    }

    // Write back introduces WAW: ftab now updated after full scan
    for (i = 1; i <= 65536; i++) {
        ftab[i] = temp[i];
    }
}
