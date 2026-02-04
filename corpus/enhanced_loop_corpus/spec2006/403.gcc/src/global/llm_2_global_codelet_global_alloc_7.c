#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern char regs_ever_live[53];
extern int local_reg_n_refs[53];
extern int local_reg_freq[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration order
    for (size_t i = 52; i < 53; i--) {
        if (regs_ever_live[i]) {
            local_reg_n_refs[i] = 0;
            local_reg_freq[i] = 0;
        }
        if (i == 0) break; // Prevent underflow since size_t wraps
    }
}
