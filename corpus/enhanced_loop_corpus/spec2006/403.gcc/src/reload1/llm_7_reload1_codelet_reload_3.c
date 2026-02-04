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
    long local_size_1 = 0;
    long local_size_2 = 0;
    int mid = 53 / 2;

    for (i = 0; i < mid; i++) {
        if (regs_ever_live[i] && !fixed_regs[i] && call_used_regs[i]) {
            local_size_1 += ((target_flags & 33554432) ? 8 : 4);
        }
    }

    for (i = mid; i < 53; i++) {
        if (regs_ever_live[i] && !fixed_regs[i] && call_used_regs[i]) {
            local_size_2 += ((target_flags & 33554432) ? 8 : 4);
        }
    }

    size += (local_size_1 + local_size_2);
}
