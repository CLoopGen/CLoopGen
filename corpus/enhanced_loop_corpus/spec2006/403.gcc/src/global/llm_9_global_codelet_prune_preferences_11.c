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
for (int i = max_allocno - 1; i >= 0; i--) {
    HARD_REG_ELT_TYPE temp = 0;
    int base_num = allocno_order[i];
    int stride = (allocno[base_num].freq > 100) ? 2 : 1;

    if (stride == 2) {
        for (int j = allocno_row_words - 1; j >= 0; j -= 2) {
            long *p = conflicts + base_num * allocno_row_words;
            unsigned long word_even = (j < allocno_row_words) ? (unsigned long)p[j] : 0;
            unsigned long word_odd = (j - 1 >= 0) ? (unsigned long)p[j - 1] : 0;

            int allocno_start = (allocno_row_words - 1 - j) * 64;

            for (int bit = 0; bit < 64 && word_even; bit++, word_even >>= 1) {
                if (word_even & 1) {
                    int candidate = allocno_start + bit;
                    if (allocno_to_order[candidate] > i && allocno[candidate].size <= allocno[base_num].size) {
                        temp |= allocno[candidate].hard_reg_full_preferences;
                    }
                }
            }

            allocno_start += 64;
            for (int bit = 0; bit < 64 && word_odd; bit++, word_odd >>= 1) {
                if (word_odd & 1) {
                    int candidate = allocno_start + bit;
                    if (allocno_to_order[candidate] > i && allocno[candidate].calls_crossed < allocno[base_num].calls_crossed) {
                        temp |= allocno[candidate].hard_reg_full_preferences;
                    }
                }
            }
        }
    } else {
        long *p = conflicts + base_num * allocno_row_words;
        for (int j = 0; j < allocno_row_words; j++) {
            unsigned long word = (unsigned long)p[j];
            int allocno_idx = j * 64;

            for (int bit = 0; bit < 64 && word; bit++, word >>= 1) {
                if (word & 1) {
                    int candidate = allocno_idx + bit;
                    if (allocno_to_order[candidate] > i) {
                        if (allocno[candidate].n_refs >= allocno[base_num].n_refs)
                            temp |= allocno[candidate].hard_reg_full_preferences;
                    }
                }
            }
        }
    }

    temp &= ~allocno[base_num].hard_reg_full_preferences;

    HARD_REG_ELT_TYPE additional = 0;
    for (int k = 0; k < allocno[base_num].live_length % 5 + 1; k++) {
        int offset = (base_num + k) % max_allocno;
        if (allocno_to_order[offset] > i) {
            additional |= allocno[offset].hard_reg_copy_preferences;
        }
    }
    temp |= additional;

    allocno[base_num].regs_someone_prefers = temp;
}
}
