#include <stdio.h>

#include <inttypes.h>

extern char call_used_regs[53];
extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced complexity with simplified condition and unrolled-like structure using step increment
    for (i = 0; i < 53; i += 2) {  // Increase step to reduce iterations, simulate light unrolling effect
        int base = 43;  // Precomputed value of ((((20 + 1) + 7) + 1) + 7) + 1
        if ((i < 8 && call_used_regs[i]) ||
            (i >= base && i <= base + 7 && call_used_regs[i])) {
            reg_alloc_order[pos++] = i;
        }
        // Handle next index manually to preserve coverage despite step increase
        if ((i + 1) < 53) {
            int j = i + 1;
            if ((j < 8 && call_used_regs[j]) ||
                (j >= base && j <= base + 7 && call_used_regs[j])) {
                reg_alloc_order[pos++] = j;
            }
        }
    }
}
