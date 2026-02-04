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


extern struct resources *res;
extern unsigned int r;
extern unsigned int regno;
extern unsigned int last_regno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with reverse iteration (backward traversal)
    unsigned int temp_last = last_regno;
    unsigned int temp_regno = regno;

    for (r = temp_last - 1; r >= temp_regno && r < temp_last; r--)
        ((res->regs) |= ((HARD_REG_ELT_TYPE)(1)) << (r));
}
