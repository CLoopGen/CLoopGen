#include <stdio.h>

#include <inttypes.h>

extern int target_flags;
extern char fixed_regs[53];
extern char call_used_regs[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_i = -1;
    for (i = 0; i < 53; i++) {
        int mask = (target_flags & 33554432) ? 2 : 1;
        if (prev_i >= 0) {
            fixed_regs[i] = (fixed_regs[prev_i] & mask) != 0;
            call_used_regs[i] = (call_used_regs[prev_i] & mask) != 0;
        } else {
            fixed_regs[i] = (fixed_regs[i] & mask) != 0;
            call_used_regs[i] = (call_used_regs[i] & mask) != 0;
        }
        prev_i = i;
    }
}
