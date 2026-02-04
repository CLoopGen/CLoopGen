#include <stdio.h>

#include <inttypes.h>

extern int *regno_src_regno;
extern int nregs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping (reverse order using indirect indexing)
    int *indices = (int*)__builtin_alloca(nregs * sizeof(int));
    for (i = 0; i < nregs; i++) {
        indices[i] = nregs - 1 - i;  // reverse mapping
    }
    for (i = 0; i < nregs; i++) {
        regno_src_regno[indices[i]] = -1;
    }
}
