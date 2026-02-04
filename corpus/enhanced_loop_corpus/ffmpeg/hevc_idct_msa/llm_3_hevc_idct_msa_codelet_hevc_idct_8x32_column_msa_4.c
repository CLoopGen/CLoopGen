#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t i;
extern  int16_t *filter_ptr1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t i;
    int16_t **indirect_array = (int16_t**)malloc(8 * sizeof(int16_t*));
    int16_t *base = filter_ptr1;
    
    // Precompute strided indirect pointers (e.g., every 16th element)
    for (i = 0; i < 8; i++) {
        indirect_array[i] = base + (i * 16);
    }

    // Variant 2: Indirect access via pointer array
    for (i = 0; i < 8; i++) {
        // Perform access through an indirection table
        int16_t *temp = indirect_array[i];
        // Simulate use to prevent optimization
        (void)temp;
    }

    // Restore semantics by updating original pointer to maintain observable behavior
    filter_ptr1 = base + (8 * 16);

    free(indirect_array);
}
