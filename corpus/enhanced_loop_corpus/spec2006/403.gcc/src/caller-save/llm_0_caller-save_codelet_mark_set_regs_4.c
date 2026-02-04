#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE this_insn_sets;
extern int regno;
extern int endregno;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 2; j++)
    for (i = regno; i < endregno; i++)
        ((this_insn_sets) |= ((HARD_REG_ELT_TYPE)(1)) << (i));
}
