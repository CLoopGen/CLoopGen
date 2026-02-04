#include <stdio.h>
#include <stdlib.h>
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

short *reg_renumber;
int max_allocno;
struct allocno *allocno;
int *allocno_order;
int i;
int nregs;

void init_vars() {
    max_allocno = 10000000; // Adjust to achieve ~0.01s runtime

    reg_renumber = (short*)calloc(2 * max_allocno, sizeof(short));
    allocno = (struct allocno*)calloc(max_allocno, sizeof(struct allocno));
    allocno_order = (int*)malloc(max_allocno * sizeof(int));

    if (!reg_renumber || !allocno || !allocno_order) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < max_allocno; idx++) {
        allocno[idx].reg = idx % (2 * max_allocno);
        allocno_order[idx] = idx;
    }

    for (int idx = 0; idx < 2 * max_allocno; idx++) {
        reg_renumber[idx] = -1;
    }

    // Set some valid reg_renumber entries to trigger condition
    for (int j = 0; j < max_allocno / 4; j++) {
        reg_renumber[allocno[j].reg] = (j % 3 == 0) ? j : -1;
    }

    nregs = 0;
}