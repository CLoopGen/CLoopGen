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


extern size_t i;
extern int max_allocno;
extern struct allocno *allocno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (size_t)max_allocno; i++) {
        int temp_size = allocno[i].size;
        int temp_live = allocno[i].live_length;
        int temp_refs = allocno[i].n_refs;
        int temp_freq = allocno[i].freq;

        // Increased arithmetic intensity with realistic use of fields
        if (temp_size == 0) {
            allocno[i].size = 1;
        } else {
            allocno[i].size = (temp_size * temp_refs + temp_freq) % (temp_size + 1) + 1;
        }

        if (temp_live == 0 || temp_refs == 0) {
            allocno[i].live_length = (temp_freq > 0) ? -temp_freq : -1;
        } else {
            allocno[i].live_length = temp_live + (temp_refs / (temp_freq + 1));
        }
    }
}
