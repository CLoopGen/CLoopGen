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


extern char global_regs[53];
extern struct resources *res;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 106; i++) {
        int index = i / 2;
        if (i % 2 == 0 && global_regs[index]) {
            ((res->regs) |= ((HARD_REG_ELT_TYPE)(1)) << (index));
        } else if (global_regs[index] && (res->memory || res->unch_memory)) {
            ((res->regs) |= ((HARD_REG_ELT_TYPE)(1)) << (index));
        }
    }
}
