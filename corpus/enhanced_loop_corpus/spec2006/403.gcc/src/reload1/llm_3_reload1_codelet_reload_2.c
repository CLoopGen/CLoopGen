#include <stdio.h>

#include <inttypes.h>

extern char fixed_regs[53];
extern char call_used_regs[53];
extern char regs_ever_live[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    int indices[53];
    for (int j = 0; j < 53; j++)
        indices[j] = j;

    for (i = 0; i < 53; i++) {
        int idx = indices[i]; // Indirect access via index array
        if (!call_used_regs[idx] && !fixed_regs[idx] && !0)
            regs_ever_live[idx] = 1;
    }
}
