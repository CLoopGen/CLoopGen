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
    // Variant 2: Indirect memory access using a precomputed index array to simulate irregular access pattern
    static const int indices[53] = {
        0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51,
        1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34, 37, 40, 43, 46, 49, 52,
        2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35, 38, 41, 44, 47, 50
    };
    for (i = 0; i < 53; i++) {
        int idx = indices[i];
        if (global_regs[idx])
            end_of_function_needs.regs |= (HARD_REG_ELT_TYPE)1 << idx;
    }
}
