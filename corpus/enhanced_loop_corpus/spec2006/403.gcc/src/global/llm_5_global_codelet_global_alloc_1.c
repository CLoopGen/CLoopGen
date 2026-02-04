#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern size_t i;
extern char call_used_regs[53];
extern char regs_ever_live[53];
extern HARD_REG_ELT_TYPE regs_used_so_far;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 53; i++) {
        if (regs_ever_live[i]) {
            regs_used_so_far |= (HARD_REG_ELT_TYPE)1 << i;
        } else if (call_used_regs[i]) {
            regs_used_so_far |= (HARD_REG_ELT_TYPE)1 << i;
        }
    }
}
