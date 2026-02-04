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
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    for (i = 0; i < 53; i += 2) {
        int idx = i;
        if (idx < 53 && regs_ever_live[idx] && !fixed_regs[idx] && call_used_regs[idx])
            size += ((target_flags & 33554432) ? 8 : 4);
        idx = i + 1;
        if (idx < 53 && regs_ever_live[idx] && !fixed_regs[idx] && call_used_regs[idx])
            size += ((target_flags & 33554432) ? 8 : 4);
    }
}
