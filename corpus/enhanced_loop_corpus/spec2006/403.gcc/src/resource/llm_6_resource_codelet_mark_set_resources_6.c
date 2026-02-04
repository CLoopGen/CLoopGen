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
    unsigned int temp_reg = regno;
    for (r = regno; r < last_regno; r++) {
        temp_reg = r;  // Introduce temporary to create a WAW dependency with previous iteration
        ((res->regs) |= ((HARD_REG_ELT_TYPE)(1)) << (temp_reg));
    }
}
