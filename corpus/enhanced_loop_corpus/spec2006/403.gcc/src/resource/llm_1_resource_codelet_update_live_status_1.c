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
if (first_regno < last_regno) {
    for (i = first_regno; i < last_regno; i += 2) {
        ((current_live_regs) |= ((HARD_REG_ELT_TYPE)(1)) << (i));
        ((pending_dead_regs) &= ~(((HARD_REG_ELT_TYPE)(1)) << (i)));
        if (i + 1 < last_regno) {
            ((current_live_regs) |= ((HARD_REG_ELT_TYPE)(1)) << (i + 1));
            ((pending_dead_regs) &= ~(((HARD_REG_ELT_TYPE)(1)) << (i + 1)));
        }
    }
}
}
