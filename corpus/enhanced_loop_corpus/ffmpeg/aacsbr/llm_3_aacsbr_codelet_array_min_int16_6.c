#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *array;
extern int nel;
extern int i;
extern int min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // Assume indices are accessed in reverse order as indirect pattern
    for (i = 1; i < nel; i++) {
        int idx = nel - 1 - i;  // Reverse indexing as indirect pattern
        if (idx >= 1)  // Ensure within valid range for comparison logic
            min = ((array[idx]) > (min) ? (min) : (array[idx]));
    }
    // Final check for first element if not covered
    if (nel > 1)
        min = ((array[0]) > (min) ? (min) : (array[0]));
}
