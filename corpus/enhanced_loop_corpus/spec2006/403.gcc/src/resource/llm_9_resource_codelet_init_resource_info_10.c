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
    for (i = 0; i < 106; i++) {
        int index = i / 2;
        if (i % 2 == 0 && global_regs[index]) {
            end_of_function_needs.regs |= ((HARD_REG_ELT_TYPE)(1)) << index;
        } else if (global_regs[index] && (index % 3 == 0)) {
            end_of_function_needs.regs |= ((HARD_REG_ELT_TYPE)(2)) << index;
        }
    }
}
