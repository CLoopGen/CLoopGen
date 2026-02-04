#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE this_insn_sets;
extern int regno;
extern int endregno;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    HARD_REG_ELT_TYPE temp_sets = this_insn_sets;
    for (i = regno; i < endregno; i++)
        temp_sets |= ((HARD_REG_ELT_TYPE)(1)) << i;
    this_insn_sets = temp_sets;
}
