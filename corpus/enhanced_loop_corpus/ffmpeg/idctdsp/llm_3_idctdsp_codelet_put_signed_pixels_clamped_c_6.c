#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *block;
extern uint8_t *restrict pixels;
extern ptrdiff_t line_size;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Flat Array Access with Pointer Arithmetic
    // Flatten the 8x8 loops into a single loop over 64 elements,
    // using consecutive memory access pattern for better cache locality.
    // This changes nested loops into a linear traversal, reducing control overhead.

    int16_t *b_ptr = block;
    uint8_t *p_ptr = pixels;
    ptrdiff_t total_size = 8 * line_size;

    for (i = 0; i < 64; i++) {
        if (*b_ptr < -128)
            *p_ptr = 0;
        else if (*b_ptr > 127)
            *p_ptr = 255;
        else
            *p_ptr = (uint8_t)(*b_ptr + 128);

        b_ptr++;
        p_ptr++;

        // After every 8 elements, skip the padding in pixels (line_size - 8)
        if ((i + 1) % 8 == 0 && i != 63) {
            p_ptr += (line_size - 8);
        }
    }
}
