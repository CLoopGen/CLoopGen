#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *restrict pixels;
extern int16_t *block;
extern int line_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process one pixel component at a time across all rows
    uint8_t *p_base = pixels;
    int16_t *b = block;
    for (i = 0; i < 8; i++) {
        // Update each column index across rows with stride 'line_size'
        p_base[0*line_size] += b[0];
        p_base[1*line_size] += b[1];
        p_base[2*line_size] += b[2];
        p_base[3*line_size] += b[3];
        p_base[4*line_size] += b[4];
        p_base[5*line_size] += b[5];
        p_base[6*line_size] += b[6];
        p_base[7*line_size] += b[7];
        b += 8;
        p_base++; // Move to next column
    }
}
