#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern char regs_ever_live[53];
extern int local_reg_n_refs[53];
extern int local_reg_freq[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 3 (forward traversal)
    for (size_t i = 0; i < 53; i += 3) {
        if (regs_ever_live[i]) {
            local_reg_n_refs[i] = 0;
            local_reg_freq[i] = 0;
        }
        // Handle remaining indices within bounds
        if (i + 1 < 53 && regs_ever_live[i + 1]) {
            local_reg_n_refs[i + 1] = 0;
            local_reg_freq[i + 1] = 0;
        }
        if (i + 2 < 53 && regs_ever_live[i + 2]) {
            local_reg_n_refs[i + 2] = 0;
            local_reg_freq[i + 2] = 0;
        }
    }
}
