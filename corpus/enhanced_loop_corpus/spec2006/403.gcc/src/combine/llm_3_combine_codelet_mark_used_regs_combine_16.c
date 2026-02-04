#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern HARD_REG_ELT_TYPE newpat_used_regs;
extern unsigned int regno;
extern unsigned int endregno;
extern unsigned int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with reverse traversal (backward iteration)
    // This changes the access pattern to descending order, maintaining consecutiveness
    for (r = endregno - 1; r >= regno; r--) {
        ((newpat_used_regs) |= ((HARD_REG_ELT_TYPE)(1)) << (r));
        if (r == 0) break; // Prevent underflow when r reaches 0 and condition is checked
    }
}
