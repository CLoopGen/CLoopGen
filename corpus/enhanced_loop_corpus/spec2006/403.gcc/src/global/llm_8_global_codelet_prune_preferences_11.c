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
for (int i = max_allocno - 1; i >= 0; i -= 2) {
    HARD_REG_ELT_TYPE temp1, temp2;
    int num1, num2;

    num1 = allocno_order[i];
    temp1 = (HARD_REG_ELT_TYPE)0;
    temp2 = (HARD_REG_ELT_TYPE)0;

    if (i - 1 >= 0) {
        num2 = allocno_order[i - 1];
    } else {
        num2 = -1;
    }

    long *p1 = conflicts + num1 * allocno_row_words;
    for (int j = allocno_row_words - 1, allocno_idx = 0; j >= 0; j--, allocno_idx += 64) {
        unsigned long word1 = (unsigned long)p1[j];
        unsigned long word2 = (num2 != -1) ? (unsigned long)(conflicts[num2 * allocno_row_words + j]) : 0;

        int a1 = allocno_idx;
        int a2 = allocno_idx;
        unsigned long w1 = word1;
        unsigned long w2 = word2;

        while (w1) {
            if (w1 & 1) {
                if (allocno_to_order[a1] > i) {
                    if (allocno[a1].size <= allocno[num1].size)
                        temp1 |= allocno[a1].hard_reg_full_preferences;
                    else
                        temp2 |= allocno[a1].hard_reg_full_preferences;
                }
            }
            w1 >>= 1;
            a1++;
        }

        while (w2) {
            if (w2 & 1) {
                if (allocno_to_order[a2] > i - 1) {
                    if (allocno[a2].size <= allocno[num2].size)
                        temp1 |= allocno[a2].hard_reg_full_preferences;
                    else
                        temp2 |= allocno[a2].hard_reg_full_preferences;
                }
            }
            w2 >>= 1;
            a2++;
        }
    }

    temp1 &= ~allocno[num1].hard_reg_full_preferences;
    temp1 |= temp2;
    allocno[num1].regs_someone_prefers = temp1;

    if (num2 != -1) {
        HARD_REG_ELT_TYPE temp3 = (HARD_REG_ELT_TYPE)0;
        HARD_REG_ELT_TYPE temp4 = (HARD_REG_ELT_TYPE)0;
        long *p2 = conflicts + num2 * allocno_row_words;

        for (int j = allocno_row_words - 1, allocno_idx = 0; j >= 0; j--, allocno_idx += 64) {
            unsigned long word = (unsigned long)p2[j];
            int a = allocno_idx;
            while (word) {
                if (word & 1) {
                    if (allocno_to_order[a] > i - 1) {
                        if (allocno[a].size <= allocno[num2].size)
                            temp3 |= allocno[a].hard_reg_full_preferences;
                        else
                            temp4 |= allocno[a].hard_reg_full_preferences;
                    }
                }
                word >>= 1;
                a++;
            }
        }
        temp3 &= ~allocno[num2].hard_reg_full_preferences;
        temp3 |= temp4;
        allocno[num2].regs_someone_prefers = temp3;
    }
}
}
