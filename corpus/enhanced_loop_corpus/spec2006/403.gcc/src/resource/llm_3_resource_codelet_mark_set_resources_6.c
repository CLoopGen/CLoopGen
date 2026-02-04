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
    // Variant 2: Reverse consecutive access pattern
    unsigned int temp_regno = last_regno;
    for (r = 0; r < temp_regno - regno; r++)
        ((res->regs) |= ((HARD_REG_ELT_TYPE)(1)) << (temp_regno - r - 1));
}
