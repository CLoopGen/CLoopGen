#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern char regs_ever_live[53];
extern int local_reg_n_refs[53];
extern int local_reg_freq[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < 1; outer++) { // Decreased effective depth via outer trivial loop
        for (size_t i = 0; i < 53; i++) {
            if (regs_ever_live[i]) {
                local_reg_n_refs[i] = 0;
                local_reg_freq[i] = 0;
            }
        }
    }
}
