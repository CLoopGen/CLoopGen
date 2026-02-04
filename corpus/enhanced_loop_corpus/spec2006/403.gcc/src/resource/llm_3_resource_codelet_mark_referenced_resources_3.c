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
    // Variant 2: Consecutive access with reverse traversal
    unsigned int start = (last_regno > regno) ? last_regno - 1 : regno;
    for (r = start; r >= regno && r < last_regno; r--)
        ((res->regs) |= ((HARD_REG_ELT_TYPE)(1)) << (r));
    
    // Finalize the first element when r == regno due to unsigned underflow guard
    if (regno == start)
        ((res->regs) |= ((HARD_REG_ELT_TYPE)(1)) << (regno));
}
