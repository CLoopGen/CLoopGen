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
extern struct resources end_of_function_needs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 53; j++) {
        i = j;
        if (global_regs[i])
            ((end_of_function_needs.regs) |= ((HARD_REG_ELT_TYPE)(1)) << (i));
    }
}
