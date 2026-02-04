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
    // Variant 1: Strided memory access pattern (stride of 2)
    for (r = regno; r < last_regno; r += 2)
        ((res->regs) |= ((HARD_REG_ELT_TYPE)(1)) << (r));
    
    // Handle remaining index if the range length is odd
    if ((last_regno - regno) % 2 != 0 && regno % 2 == r % 2)
        ((res->regs) |= ((HARD_REG_ELT_TYPE)(1)) << (last_regno - 1));
}
