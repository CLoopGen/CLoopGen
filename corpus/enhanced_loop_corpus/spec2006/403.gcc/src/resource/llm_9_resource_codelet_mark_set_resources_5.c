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
    for (r = 0; r < 106; r++) {
        unsigned int idx = r / 2;
        if ((r % 2 == 0) && (call_used_regs[idx] || global_regs[idx]))
            ((res->regs) |= ((HARD_REG_ELT_TYPE)(1)) << (idx));
    }
}
