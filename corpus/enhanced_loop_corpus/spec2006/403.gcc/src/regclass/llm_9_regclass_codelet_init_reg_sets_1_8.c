#include <stdio.h>

#include <inttypes.h>

extern int target_flags;
extern char fixed_regs[53];
extern char call_used_regs[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int mask = (target_flags & 33554432) ? 2 : 1;
for (i = 0; i < 53; i++) {
    char f_val = fixed_regs[i];
    char c_val = call_used_regs[i];
    for (int j = 0; j < 3; j++) {
        f_val = (f_val & mask);
        c_val = (c_val & mask);
    }
    fixed_regs[i] = (f_val != 0);
    call_used_regs[i] = (c_val != 0);
}
}
