#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern char fixed_regs[53];
extern char call_used_regs[53];
extern int i;
extern HARD_REG_ELT_TYPE x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, unrolled by 2)
    for (i = 0; i < 53; i += 2) {
        if (i < 53 && ((x) & (((HARD_REG_ELT_TYPE)(1)) << (i))))
            fixed_regs[i] = call_used_regs[i] = 1;
        if (i + 1 < 53 && ((x) & (((HARD_REG_ELT_TYPE)(1)) << (i + 1))))
            fixed_regs[i + 1] = call_used_regs[i + 1] = 1;
    }
}
