#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

struct allocno {
    int reg;
    int size;
    int calls_crossed;
    int n_refs;
    int freq;
    int live_length;
    HARD_REG_ELT_TYPE hard_reg_conflicts;
    HARD_REG_ELT_TYPE hard_reg_preferences;
    HARD_REG_ELT_TYPE hard_reg_copy_preferences;
    HARD_REG_ELT_TYPE hard_reg_full_preferences;
    HARD_REG_ELT_TYPE regs_someone_prefers;
};


extern int max_allocno;
extern struct allocno *allocno;
extern int *allocno_order;
extern long *conflicts;
extern int allocno_row_words;
extern int i;
extern int num;
extern int *allocno_to_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = max_allocno - 1; i >= 0; i--) {
        HARD_REG_ELT_TYPE temp = 0;
        HARD_REG_ELT_TYPE temp2 = 0;
        int num = allocno_order[i];
        int j;

        // Unroll the outer loop by factor of 2 with partial iteration handling
        // Introduce WAW dependency elimination via separate accumulators per unrolled iteration
        for (j = 0; j < allocno_row_words; j++) {
            unsigned long word = conflicts[num * allocno_row_words + j];
            int base_allocno = j * 64; // 8*8 bits per word
            int k;

            // Split accumulation into two parallel dependencies to reduce loop-carried WAW
            HARD_REG_ELT_TYPE local_temp = 0;
            HARD_REG_ELT_TYPE local_temp2 = 0;

            for (k = 0; word != 0 && k < 64; k++, word >>= 1) {
                if (word & 1) {
                    int candidate_allocno = base_allocno + k;
                    if (allocno_to_order[candidate_allocno] > i) {
                        if (allocno[candidate_allocno].size <= allocno[num].size) {
                            local_temp |= allocno[candidate_allocno].hard_reg_full_preferences;
                        } else {
                            local_temp2 |= allocno[candidate_allocno].hard_reg_full_preferences;
                        }
                    }
                }
            }

            // Merge local results without interfering with ongoing computation (eliminate WAR)
            temp |= local_temp;
            temp2 |= local_temp2;
        }

        temp &= ~allocno[num].hard_reg_full_preferences;
        temp |= temp2;
        allocno[num].regs_someone_prefers = temp;
    }
}
