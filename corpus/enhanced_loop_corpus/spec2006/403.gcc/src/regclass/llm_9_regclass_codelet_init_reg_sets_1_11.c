#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern char fixed_regs[53];
extern char call_used_regs[53];
extern int i;
extern HARD_REG_ELT_TYPE x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 26; i++) {
        HARD_REG_ELT_TYPE mask1 = ((HARD_REG_ELT_TYPE)(1)) << i;
        HARD_REG_ELT_TYPE mask2 = ((HARD_REG_ELT_TYPE)(1)) << (i + 26);
        if ((x & mask1))
            fixed_regs[i] = call_used_regs[i] = 1;
        if ((x & mask2))
            fixed_regs[i + 26] = call_used_regs[i + 26] = 1;
    }
}
