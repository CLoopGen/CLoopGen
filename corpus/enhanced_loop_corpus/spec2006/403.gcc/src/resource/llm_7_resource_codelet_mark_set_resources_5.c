#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

struct resources {
    char memory;
    char unch_memory;
    char volatil;
    char cc;
    HARD_REG_ELT_TYPE regs;
};


extern char call_used_regs[53];
extern char global_regs[53];
extern struct resources *res;
extern unsigned int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    HARD_REG_ELT_TYPE local_reg_mask = 0;
    for (r = 0; r < 53; r++) {
        char used = call_used_regs[r] || global_regs[r];
        local_reg_mask <<= 1;
        local_reg_mask |= used;
    }
    res->regs |= local_reg_mask;
}
