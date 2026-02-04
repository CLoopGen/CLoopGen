#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Introduce additional WAR and WAW dependencies via temporary buffer and reverse iteration
    // Increases data dependencies by using a temporary array and writing back in reverse order.
    // Simulates a scenario with artificial write-after-read and write-after-write hazards.
    
    Int32 temp[257];
    for (i = 1; i < 257; i++) {
        temp[i] = ftab[i];  // Copy to temp (introduces WAR if concurrent)
    }
    for (i = 256; i >= 1; i--) {
        if (i > 1) {
            temp[i] += temp[i - 1];
        }
        ftab[i] = temp[i];  // WAW: ftab written after temp is used
    }
}
