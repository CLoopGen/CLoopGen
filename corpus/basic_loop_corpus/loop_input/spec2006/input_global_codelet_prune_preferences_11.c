#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int max_allocno = 4096;
struct allocno *allocno;
int *allocno_order;
long *conflicts;
int allocno_row_words;
int i;
int num;
int *allocno_to_order;

void init_vars() {
    const int data_size = 1 << 20; // ~8MB of conflict data, reasonable for ~0.01s runtime
    allocno_row_words = 64; // each row has 64 longs -> 512 bits per allocno

    max_allocno = data_size / (allocno_row_words * sizeof(long));
    if (max_allocno < 16) max_allocno = 16;
    if (max_allocno > 8192) max_allocno = 8192;

    allocno = (struct allocno*)calloc(max_allocno, sizeof(struct allocno));
    allocno_order = (int*)malloc(max_allocno * sizeof(int));
    conflicts = (long*)calloc(max_allocno * allocno_row_words, sizeof(long));
    allocno_to_order = (int*)malloc(max_allocno * sizeof(int));

    srand(0);
    for (int idx = 0; idx < max_allocno; idx++) {
        allocno[idx].reg = rand() % 32;
        allocno[idx].size = 1 + rand() % 8;
        allocno[idx].calls_crossed = rand() % 10;
        allocno[idx].n_refs = rand() % 100;
        allocno[idx].freq = rand() % 1000;
        allocno[idx].live_length = rand() % 200;
        allocno[idx].hard_reg_conflicts = rand();
        allocno[idx].hard_reg_preferences = rand();
        allocno[idx].hard_reg_copy_preferences = rand();
        allocno[idx].hard_reg_full_preferences = rand();
        allocno[idx].regs_someone_prefers = 0;

        allocno_order[idx] = max_allocno - 1 - idx;
        allocno_to_order[idx] = idx;
    }

    for (int r = 0; r < max_allocno; r++) {
        long *row = conflicts + r * allocno_row_words;
        for (int w = 0; w < allocno_row_words; w++) {
            row[w] = (rand() | ((long)rand() << 32)) & ((w == 0) ? ~0UL : 0xFFFFFFFFFFFFUL);
        }
        // Ensure diagonal symmetry is avoided: clear self-conflict
        int word_idx = 0;
        int bit_idx = r;
        while (bit_idx >= 64) { bit_idx -= 64; word_idx++; }
        if (word_idx < allocno_row_words)
            row[word_idx] &= ~(1UL << bit_idx);
    }
}