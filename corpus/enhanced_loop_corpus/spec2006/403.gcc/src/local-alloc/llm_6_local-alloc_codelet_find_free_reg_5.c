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
    HARD_REG_ELT_TYPE temp_used = used;
    for (ins = born_index; ins < dead_index; ins++)
        temp_used |= regs_live_at[ins];
    used = temp_used;
}
