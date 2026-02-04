#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern unsigned int start_regno;
extern unsigned int end_regno;
extern unsigned int r;
extern HARD_REG_ELT_TYPE *used_in_set;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern (stride of 2)
    // Note: used_in_set is a pointer to a single HARD_REG_ELT_TYPE, so we simulate striding by applying the operation
    // on every other bit within the same word, effectively skipping every other register index.
    for (r = start_regno; r < end_regno; r += 2)
        ((*used_in_set) &= ~(((HARD_REG_ELT_TYPE)(1)) << (r)));
}
