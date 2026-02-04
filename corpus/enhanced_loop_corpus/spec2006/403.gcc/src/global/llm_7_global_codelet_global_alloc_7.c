#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern char regs_ever_live[53];
extern int local_reg_n_refs[53];
extern int local_reg_freq[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int sum_n_refs = 0;
    int sum_freq = 0;
    for (i = 0; i < 53; i++) {
        if (regs_ever_live[i]) {
            local_reg_n_refs[i] = sum_n_refs;
            local_reg_freq[i] = sum_freq;
            sum_n_refs += 1;
            sum_freq += 2;
        } else {
            local_reg_n_refs[i] = -1;
            local_reg_freq[i] = -1;
        }
    }
}
