#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern char fixed_regs[53];
extern char call_used_regs[53];
extern int i;
extern HARD_REG_ELT_TYPE x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    HARD_REG_ELT_TYPE local_x = x;
    for (i = 0, j = 52; i < 53; i++, j--) {
        if (((local_x) & (((HARD_REG_ELT_TYPE)(1)) << (j))))
            fixed_regs[j] = call_used_regs[j] = 1;
    }
}
