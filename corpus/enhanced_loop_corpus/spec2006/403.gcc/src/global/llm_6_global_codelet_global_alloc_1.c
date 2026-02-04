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
    HARD_REG_ELT_TYPE temp_regs = regs_used_so_far;
    for (i = 0; i < 53; i++) {
        if (regs_ever_live[i] || call_used_regs[i]) {
            temp_regs |= ((HARD_REG_ELT_TYPE)(1)) << i;
        }
    }
    regs_used_so_far = temp_regs;
}
