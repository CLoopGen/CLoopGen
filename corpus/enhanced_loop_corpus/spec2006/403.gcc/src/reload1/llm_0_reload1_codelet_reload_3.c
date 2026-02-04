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
for (i = 0; i < 53; i++)
    for (int j = 0; j < 1; j++)
        if (regs_ever_live[i] && !fixed_regs[i] && call_used_regs[i])
            size += ((target_flags & 33554432) ? 8 : 4);
}
