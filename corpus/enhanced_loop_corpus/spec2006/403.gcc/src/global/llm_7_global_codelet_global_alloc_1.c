#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern size_t i;
extern char call_used_regs[53];
extern char regs_ever_live[53];
extern HARD_REG_ELT_TYPE regs_used_so_far;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    HARD_REG_ELT_TYPE local_accumulator = 0;
    for (i = 0; i < 53; i++) {
        if (regs_ever_live[i] && call_used_regs[i]) {
            local_accumulator |= ((HARD_REG_ELT_TYPE)(1)) << (i % 64);
        }
    }
    regs_used_so_far |= local_accumulator;
}
