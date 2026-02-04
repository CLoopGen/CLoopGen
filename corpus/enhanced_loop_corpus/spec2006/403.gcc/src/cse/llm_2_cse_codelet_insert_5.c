#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE hard_regs_in_table;
extern unsigned int regno;
extern unsigned int endregno;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern (stride of 2)
    // Simulate strided behavior by updating every second element in logical sequence
    for (i = regno; i < endregno; i += 2)
        ((hard_regs_in_table) |= ((HARD_REG_ELT_TYPE)(1)) << (i));
    
    // Handle remaining index if range length is odd
    if ((endregno - regno) % 2 == 1 && regno % 2 == 0)
        ((hard_regs_in_table) |= ((HARD_REG_ELT_TYPE)(1)) << (endregno - 1));
}
