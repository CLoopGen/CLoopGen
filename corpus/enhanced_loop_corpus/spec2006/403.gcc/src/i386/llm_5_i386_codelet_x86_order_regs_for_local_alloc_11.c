#include <stdio.h>

#include <inttypes.h>

extern char call_used_regs[53];
extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 53; i++) {
        int cond1 = (i < 8);
        int base = (((((20 + 1) + 7) + 1) + 7) + 1);
        int cond2 = (i >= base && i <= base + 7);
        int meets_range = cond1 || cond2;
        if (meets_range && call_used_regs[i]) {
            reg_alloc_order[pos++] = i;
        }
    }
}
