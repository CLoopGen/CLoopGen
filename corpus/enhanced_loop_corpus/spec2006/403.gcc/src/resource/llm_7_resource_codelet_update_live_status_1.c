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
    HARD_REG_ELT_TYPE mask_live = 0;
    HARD_REG_ELT_TYPE mask_dead = ~((HARD_REG_ELT_TYPE)0);
    for (i = first_regno; i < last_regno; i++) {
        mask_live |= ((HARD_REG_ELT_TYPE)(1)) << i;
        mask_dead &= ~(((HARD_REG_ELT_TYPE)(1)) << i);
    }
    current_live_regs |= mask_live;
    pending_dead_regs &= mask_dead;
}
