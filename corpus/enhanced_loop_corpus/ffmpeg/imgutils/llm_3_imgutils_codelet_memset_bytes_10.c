#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *clear;
extern size_t clear_size;
extern int same;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    // Create a local index array on stack only if clear_size is reasonable
    #define MAX_SIZE 1024
    if (clear_size == 0) {
        same = 1;
        return;
    }
    size_t indices[MAX_SIZE];
    if (clear_size > MAX_SIZE) {
        // Fallback for large sizes: use direct check
        for (i = 0; i < clear_size; i++) {
            if (clear[i] != clear[0]) {
                same = 0;
                return;
            }
        }
        same = 1;
        return;
    }
    // Populate index array
    for (i = 0; i < clear_size; i++) {
        indices[i] = i;
    }
    // Use indirect access through indices
    same = 1;
    for (i = 0; i < clear_size; i++) {
        if (clear[indices[i]] != clear[0]) {
            same = 0;
            break;
        }
    }
}
