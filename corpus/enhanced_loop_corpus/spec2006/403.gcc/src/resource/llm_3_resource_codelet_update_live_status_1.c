#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE current_live_regs;
extern HARD_REG_ELT_TYPE pending_dead_regs;
extern int first_regno;
extern int last_regno;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access in reverse order (backward traversal)
    // Change access pattern to go from last_regno-1 down to first_regno
    for (i = last_regno - 1; i >= first_regno; i--) {
        ((current_live_regs) |= ((HARD_REG_ELT_TYPE)(1)) << (i));
        ((pending_dead_regs) &= ~(((HARD_REG_ELT_TYPE)(1)) << (i)));
    }
}
