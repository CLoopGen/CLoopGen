#include <stdio.h>

#include <inttypes.h>

extern int target_flags;
extern char fixed_regs[53];
extern char call_used_regs[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 53; i++) {
    if (!(target_flags & 33554432)) {
        fixed_regs[i] = (fixed_regs[i] & 1) != 0;
        call_used_regs[i] = (call_used_regs[i] & 1) != 0;
        continue;
    }
    fixed_regs[i] = (fixed_regs[i] & 2) != 0;
    call_used_regs[i] = (call_used_regs[i] & 2) != 0;
}
}
