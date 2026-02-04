#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int linesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access Pattern with Linear Indexing
    // Flatten the 2D access into a linear pass over memory, ensuring consecutive accesses.
    // We compute the valid inner region and traverse it in one loop with direct pointer arithmetic.
    uint8_t *base = data + linesize + 1; // Start at (1,1)
    int inner_width = w - 2;
    int row_skip = linesize - inner_width;
    
    uint8_t *ptr = base;
    for (int i = 0; i < (h - 2); i++) {
        for (int j = 0; j < inner_width; j++) {
            *ptr = ((*ptr) >> 2) + (*ptr);
            ptr++;
        }
        ptr += row_skip; // Skip to next valid row
    }
}
