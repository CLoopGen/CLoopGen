#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE *regs_live_at;
extern int born_index;
extern int dead_index;
extern int ins;
extern HARD_REG_ELT_TYPE used;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    HARD_REG_ELT_TYPE local_used = 0;
    int i;
    for (i = born_index; i < dead_index; i++) {
        local_used |= regs_live_at[i];
        regs_live_at[i] = regs_live_at[i]; // Artificial WAW dependency: write after write
    }
    used |= local_used;
}
