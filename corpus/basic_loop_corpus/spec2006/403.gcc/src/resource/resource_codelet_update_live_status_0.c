#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE current_live_regs;
extern int first_regno;
extern int last_regno;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = first_regno; i < last_regno; i++)
    ((current_live_regs) &= ~(((HARD_REG_ELT_TYPE)(1)) << (i)));

}
