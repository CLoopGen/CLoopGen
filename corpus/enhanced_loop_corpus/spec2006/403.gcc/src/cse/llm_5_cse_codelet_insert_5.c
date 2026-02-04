#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE hard_regs_in_table;
extern unsigned int regno;
extern unsigned int endregno;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = regno; i < endregno; i++) {
        if (i >= regno + 5) {
            continue;
        }
        hard_regs_in_table |= ((HARD_REG_ELT_TYPE)(1)) << i;
    }
}
