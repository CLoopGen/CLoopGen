#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef int Int32;

extern UChar pos[6];
extern Int32 i;
extern Int32 nGroups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate loop-carried dependencies entirely by decoupling writes.
    // Introduce parallelism potential by using an offset-based write with no inter-iteration dependencies.
    // Also, add a temporary variable to break direct assignment pattern (eliminates potential WAR hazards).
    Int32 temp;
    for (i = 0; i < nGroups; i++) {
        temp = i;           // Local computation
        pos[i] = temp;      // Write with no dependency on previous or future iterations
    }
}
