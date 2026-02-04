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
    HARD_REG_ELT_TYPE temp_regs = res->regs;
    for (i = 0; i < 53; i++) {
        if (global_regs[i]) {
            temp_regs |= ((HARD_REG_ELT_TYPE)(1)) << i;
        }
    }
    res->regs = temp_regs;
}
