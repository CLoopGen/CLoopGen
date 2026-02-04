#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 temp = 0;
    for (i = 0; i < 23; i++) {
        temp = base[i] + temp;  // Introduce RAW dependency: temp depends on previous iteration
        base[i] = temp;         // WAW: base[i] written after potential prior write in reordered context
        temp = 0;               // Reset to break full accumulation, but dependency chain remains per iteration
    }
}
