#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern char fixed_regs[53];
extern char call_used_regs[53];
extern int i;
extern HARD_REG_ELT_TYPE x;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 53; i++)
    if (((x) & (((HARD_REG_ELT_TYPE)(1)) << (i))))
        fixed_regs[i] = call_used_regs[i] = 1;

}
