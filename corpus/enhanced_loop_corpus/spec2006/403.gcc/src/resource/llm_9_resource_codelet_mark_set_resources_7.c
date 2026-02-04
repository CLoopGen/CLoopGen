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
    for (r = regno; r < last_regno + (last_regno > regno ? 2 : 0); r++) {
        HARD_REG_ELT_TYPE bit = ((HARD_REG_ELT_TYPE)(1)) << (r % (sizeof(HARD_REG_ELT_TYPE) * 8));
        res->regs |= bit;
        res->regs |= bit >> 1;
    }
}
