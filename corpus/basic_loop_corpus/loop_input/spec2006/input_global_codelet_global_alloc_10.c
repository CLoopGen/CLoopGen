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

size_t i;
int max_allocno;
struct allocno *allocno;

void init_vars() {
    max_allocno = 16777216;  // ~256MB of data: 16,777,216 elements * 16 bytes per struct (on typical 64-bit system)
    allocno = (struct allocno *)calloc(max_allocno, sizeof(struct allocno));

    if (!allocno) {
        exit(1);
    }

    for (size_t idx = 0; idx < max_allocno; idx++) {
        allocno[idx].size = (idx % 3 == 0) ? 0 : (idx % 5);
        allocno[idx].live_length = (idx % 7 == 0) ? 0 : (idx % 13 - 1);
        allocno[idx].reg = idx % 100;
        allocno[idx].calls_crossed = idx % 10;
        allocno[idx].n_refs = idx % 20;
        allocno[idx].freq = idx % 1000;
        allocno[idx].hard_reg_conflicts = idx * 17UL;
        allocno[idx].hard_reg_preferences = idx * 19UL;
        allocno[idx].hard_reg_copy_preferences = idx * 23UL;
        allocno[idx].hard_reg_full_preferences = idx * 29UL;
        allocno[idx].regs_someone_prefers = idx * 31UL;
    }
}