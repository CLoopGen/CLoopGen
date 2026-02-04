#include <stdio.h>

#include <inttypes.h>

extern int target_flags;
extern char fixed_regs[53];
extern char call_used_regs[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 53; i += 2) {
    int mask = (target_flags & 33554432) ? 2 : 1;
    fixed_regs[i] = (fixed_regs[i] & mask) != 0;
    if (i + 1 < 53) {
        fixed_regs[i+1] = (fixed_regs[i+1] & mask) != 0;
        call_used_regs[i] = (call_used_regs[i] & mask) != 0;
        call_used_regs[i+1] = (call_used_regs[i+1] & mask) != 0;
    } else {
        call_used_regs[i] = (call_used_regs[i] & mask) != 0;
    }
}
}
