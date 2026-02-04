#include <stdio.h>

#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

extern unsigned int start_regno;
extern unsigned int end_regno;
extern unsigned int r;
extern HARD_REG_ELT_TYPE *used_in_set;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with reverse iteration order
    // This changes the memory access pattern by iterating from end_regno-1 down to start_regno,
    // maintaining consecutive bit clearing but in reverse order.
    for (r = end_regno - 1; r >= start_regno; r--) {
        ((*used_in_set) &= ~(((HARD_REG_ELT_TYPE)(1)) << (r)));
        if (r == 0) break; // Prevent underflow when r reaches 0 and condition rechecks
    }
}
