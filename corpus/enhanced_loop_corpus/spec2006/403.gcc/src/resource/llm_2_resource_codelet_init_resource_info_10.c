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
    // Variant 1: Strided memory access with stride of 2, unrolling by 2 to maintain coverage
    for (i = 0; i < 53; i += 2) {
        if (i < 53 && global_regs[i])
            end_of_function_needs.regs |= (HARD_REG_ELT_TYPE)1 << i;
        if (i + 1 < 53 && global_regs[i + 1])
            end_of_function_needs.regs |= (HARD_REG_ELT_TYPE)1 << (i + 1);
    }
}
