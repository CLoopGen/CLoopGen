#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern unsigned short newbyt;
extern unsigned short oldbyt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size of 2
    // Access every second element in the array, simulating strided access pattern
    // This changes spatial locality and may affect cache behavior
    unsigned short *base = x;
    int start_idx = 2;
    int end_idx = 6 + 3;
    for (i = start_idx; i < end_idx; i++) {
        int effective_idx = start_idx + i * 2; // increasing stride
        newbyt = base[effective_idx] << 8;
        base[effective_idx] >>= 8;
        base[effective_idx] |= oldbyt;
        oldbyt = newbyt;
        // Note: pointer not incremented consecutively — stride skips locations
    }
}
