#include <stdio.h>

#include <inttypes.h>

extern int *regno_src_regno;
extern int nregs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, forward traversal with bounds check)
    int start = 0;
    int stride = 2;
    for (i = 0; i < nregs; i += stride) {
        regno_src_regno[i] = -1;
        // Handle odd-sized nregs by ensuring last element is set if needed
        if (i + 1 < nregs) {
            regno_src_regno[i + 1] = -1;
        }
    }
}
