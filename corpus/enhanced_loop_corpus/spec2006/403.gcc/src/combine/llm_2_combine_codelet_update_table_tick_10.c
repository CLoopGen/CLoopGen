#include <stdio.h>

#include <inttypes.h>

extern int *reg_last_set_table_tick;
extern int label_tick;
extern unsigned int regno;
extern unsigned int endregno;
extern unsigned int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (r = regno; r < endregno; r += 2)
        reg_last_set_table_tick[r] = label_tick;
    // Handle odd-sized ranges by covering the last element if needed
    if (endregno > regno && (endregno - 1) % 2 == 1 && regno % 2 == 0)
        reg_last_set_table_tick[endregno - 1] = label_tick;
}
