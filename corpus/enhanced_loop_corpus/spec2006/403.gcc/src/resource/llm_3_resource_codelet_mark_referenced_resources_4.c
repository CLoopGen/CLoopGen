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
extern struct resources *res;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a precomputed index array to simulate indirect pattern
    int indices[53];
    for (int j = 0; j < 53; j++)
        indices[j] = 52 - j;  // reverse order access: 52, 51, ..., 0

    for (i = 0; i < 53; i++) {
        int idx = indices[i];  // indirect access via lookup
        if (global_regs[idx])
            ((res->regs) |= ((HARD_REG_ELT_TYPE)(1)) << (idx));
    }
}
