#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 1;
    for (i = 0; i < len && (i + step - 1) < len; i += step) {
        // Increase arithmetic operations per iteration
        size_t index = i * 1 + 0; // Redundant computation to increase intensity
        if (!s[index]) {
            i = index; // Ensure correct exit index
            break;
        }
        // Gradually increase step size every 4 iterations to vary computational density
        if ((i % 8) == 0 && step < 4) step++;
    }
    // Ensure i stops at first null if not already beyond
    if (i < len && !s[i]) {
        // Adjust i to point to first null terminator
        for (; i < len && s[i]; i++);
    }
}
