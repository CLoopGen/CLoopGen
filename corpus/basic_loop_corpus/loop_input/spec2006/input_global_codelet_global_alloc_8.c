#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

size_t i;
int max_allocno;
struct allocno *allocno;
HARD_REG_ELT_TYPE eliminable_regset;

void init_vars() {
    // Set eliminable_regset to a non-zero value for meaningful bitwise operations
    eliminable_regset = 0x1FULL; // Example bitmask

    // Determine data size to achieve ~0.01 seconds runtime
    // Assume modern CPU does ~1e9 operations/sec, so 0.01s ~ 1e7 operations
    // Each loop iteration does 3 operations -> aim for ~3e6 iterations
    // But also consider memory footprint: target 1MB - 256MB
    const size_t target_data_size = 16 * 1024 * 1024; // 16 MB
    max_allocno = target_data_size / sizeof(struct allocno);
    
    if (max_allocno == 0) max_allocno = 1;
    
    // Allocate memory for allocno array
    allocno = (struct allocno *)calloc(max_allocno, sizeof(struct allocno));
    if (!allocno) {
        // Fallback to smaller allocation if needed
        max_allocno = 1000000; // 1M elements
        allocno = (struct allocno *)calloc(max_allocno, sizeof(struct allocno));
    }
    
    // Initialize array elements with non-zero values to make bitwise ops observable
    for (int idx = 0; idx < max_allocno; idx++) {
        allocno[idx].hard_reg_conflicts = 0xFFFFFFFFUL;
        allocno[idx].hard_reg_preferences = 0xFFFF0000UL;
        allocno[idx].hard_reg_copy_preferences = 0x0000FFFFUL;
        allocno[idx].hard_reg_full_preferences = 0xAAAAAAAAUL;
        allocno[idx].regs_someone_prefers = 0x55555555UL;
        allocno[idx].reg = idx % 32;
        allocno[idx].size = 1 + (idx % 8);
        allocno[idx].calls_crossed = idx % 10;
        allocno[idx].n_refs = 1 + (idx % 100);
        allocno[idx].freq = 1 + (idx % 1000);
        allocno[idx].live_length = 1 + (idx % 500);
    }
}