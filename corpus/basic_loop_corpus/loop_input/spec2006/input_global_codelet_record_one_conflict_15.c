#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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
int regno;
int j;
int i_;
int allocno_;
long *p_;

static struct allocno *allocno_buf;
static long *p_buf;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec runtime estimate
    const size_t num_allocnos = total_data_size / sizeof(struct allocno);
    const size_t num_long_words = (num_allocnos + 8 * 8 - 1) / (8 * 8);

    allocno_buf = calloc(num_allocnos, sizeof(struct allocno));
    p_buf = malloc(num_long_words * sizeof(long));

    if (!allocno_buf || !p_buf) {
        exit(1);
    }

    for (size_t i = 0; i < num_long_words; i++) {
        p_buf[i] = (i % 3) ? (1UL << (i % 32)) : 0;
    }

    allocno = allocno_buf;
    p_ = p_buf;
    allocno_row_words = (int)num_long_words;
    regno = 5;
    j = 0;
    i_ = 0;
    allocno_ = 0;
}