#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE newpat_used_regs;
extern unsigned int regno;
extern unsigned int endregno;
extern unsigned int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with conditional bit setting based on stride pattern
    // Only processes every second register, halving the number of iterations
    // Introduces conditional logic to maintain correctness under reduced frequency
    for (r = regno; r < endregno; r += 2) {
        HARD_REG_ELT_TYPE mask = ((HARD_REG_ELT_TYPE)1) << r;
        if (r + 1 < endregno) {
            mask |= ((HARD_REG_ELT_TYPE)1) << (r + 1);
        }
        newpat_used_regs |= mask;
    }
}
