#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (processing every second element in reverse)
    // This changes the access pattern from sequential to strided, reducing data reuse but altering memory traversal.
    for (i = (2 * size - 2) & ~1; i >= 0; i -= 2) {
        if (i + 1 < 2*size && i - 1 >= 0) {
            filtered_top[i] = (top[i + 1] + 2 * top[i] + top[i - 1] + 2) >> 2;
        }
    }
    // Process odd indices in a separate pass to maintain coverage (simulating strided pattern over full range)
    for (i = (2 * size - 3) | 1; i >= 1; i -= 2) {
        filtered_top[i] = (top[i + 1] + 2 * top[i] + top[i - 1] + 2) >> 2;
    }
}
