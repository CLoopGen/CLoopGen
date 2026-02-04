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
    int stride = 1;
    for (ins = born_index; ins < dead_index; ins += stride)
        for (int unroll_factor = 0; unroll_factor < 1; unroll_factor++)
            ((used) |= (regs_live_at[ins]));
}
