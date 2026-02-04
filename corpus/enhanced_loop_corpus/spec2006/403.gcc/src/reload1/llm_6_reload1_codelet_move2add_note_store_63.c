#include <stdio.h>

#include <inttypes.h>

extern int reg_set_luid[53];
extern unsigned int regno;
extern unsigned int i;
extern unsigned int endregno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce a loop-carried WAW (Write-After-Write) dependency
    // by splitting the initialization into two phases with an artificial dependence.
    // We first write a sentinel value, then overwrite with the final value.
    for (i = regno; i < endregno; i++) {
        reg_set_luid[i] = -1;  // First write: mark as initialized
    }
    for (i = regno; i < endregno; i++) {
        reg_set_luid[i] = 0;   // Second write: set to final value (WAW dependency on previous loop)
    }
}
