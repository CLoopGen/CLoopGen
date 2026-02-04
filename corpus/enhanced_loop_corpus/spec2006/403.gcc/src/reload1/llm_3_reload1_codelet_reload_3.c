#include <stdio.h>

#include <inttypes.h>

extern int target_flags;
extern char fixed_regs[53];
extern char call_used_regs[53];
extern char regs_ever_live[53];
extern int i;
extern long size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a predefined index array to simulate non-sequential access
    static const int access_order[53] = {
        52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40,
        39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27,
        26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14,
        13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
    };
    for (i = 0; i < 53; i++) {
        int idx = access_order[i];
        if (regs_ever_live[idx] && !fixed_regs[idx] && call_used_regs[idx])
            size += ((target_flags & 33554432) ? 8 : 4);
    }
}
