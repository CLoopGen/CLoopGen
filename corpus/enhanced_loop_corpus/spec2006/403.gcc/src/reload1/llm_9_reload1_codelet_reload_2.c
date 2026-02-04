#include <stdio.h>

#include <inttypes.h>

extern char fixed_regs[53];
extern char call_used_regs[53];
extern char regs_ever_live[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 53; i++) {
        for (j = 0; j < 3; j++) {
            if (!call_used_regs[i] && !fixed_regs[i] && (j == 1))
                regs_ever_live[i] = 1;
        }
    }
}
