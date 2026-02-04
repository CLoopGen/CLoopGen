#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

struct allocno *allocno;
int allocno_row_words;
int j;
HARD_REG_ELT_TYPE this_reg;
int i_;
int allocno_;
long *p_;

void init_vars() {
    const int total_allocnos = 1 << 20;
    allocno_row_words = 8;
    this_reg = 1UL << 3; 
    allocno_ = 0;
    i_ = 0;

    allocno = calloc(total_allocnos, sizeof(struct allocno));
    if (!allocno) exit(1);

    p_ = calloc(allocno_row_words, sizeof(long));
    if (!p_) exit(1);

    p_[0] = 0xAAAAAAAAUL;
    p_[1] = 0x55555555UL;
    p_[2] = 0xCCCCCCCCUL;
    p_[3] = 0x33333333UL;
    p_[4] = 0xF0F0F0F0UL;
    p_[5] = 0x0F0F0F0FUL;
    p_[6] = 0xFF00FF00UL;
    p_[7] = 0x00FF00FFUL;

    for (int i = 0; i < total_allocnos; i++) {
        allocno[i].hard_reg_conflicts = 0;
    }
}