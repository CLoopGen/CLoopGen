#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern size_t i;
extern char call_used_regs[53];
extern char regs_ever_live[53];
extern HARD_REG_ELT_TYPE regs_used_so_far;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t unroll_factor = 4;
    size_t limit = 53 - (53 % unroll_factor);
    for (i = 0; i < limit; i += unroll_factor) {
        if (regs_ever_live[i] || call_used_regs[i])
            regs_used_so_far |= (HARD_REG_ELT_TYPE)1 << i;
        if (regs_ever_live[i+1] || call_used_regs[i+1])
            regs_used_so_far |= (HARD_REG_ELT_TYPE)1 << (i+1);
        if (regs_ever_live[i+2] || call_used_regs[i+2])
            regs_used_so_far |= (HARD_REG_ELT_TYPE)1 << (i+2);
        if (regs_ever_live[i+3] || call_used_regs[i+3])
            regs_used_so_far |= (HARD_REG_ELT_TYPE)1 << (i+3);
    }
    for (; i < 53; i++) {
        if (regs_ever_live[i] || call_used_regs[i])
            regs_used_so_far |= (HARD_REG_ELT_TYPE)1 << i;
    }
}
