#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *block;
extern ptrdiff_t stride;
extern int height;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — traverse vertically with a fixed column index (e.g., column 0)
    uint8_t *temp_block = block;
    int col_offset = 0; // Access first element of each row
    for (y = 0; y < height; y++) {
        volatile uint8_t value = temp_block[col_offset]; // Strided access down a column
        temp_block += stride; // Move to same column in next row
    }
}
