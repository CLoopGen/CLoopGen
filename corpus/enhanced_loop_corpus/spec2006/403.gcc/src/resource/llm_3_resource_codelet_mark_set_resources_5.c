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


extern char call_used_regs[53];
extern char global_regs[53];
extern struct resources *res;
extern unsigned int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal with direct indexing
    // Process array from last to first element to test backward memory access patterns
    for (r = 52; r < 53; r--) {
        if (call_used_regs[r] || global_regs[r])
            ((res->regs) |= ((HARD_REG_ELT_TYPE)(1)) << (r));
        if (r == 0) break; // Prevent underflow since r is unsigned
    }
}
