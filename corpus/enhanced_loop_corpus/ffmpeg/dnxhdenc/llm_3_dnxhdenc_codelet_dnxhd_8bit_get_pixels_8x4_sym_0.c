#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *restrict block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process one column at a time (vertical traversal)
    int16_t *b = block;
    uint8_t *p = pixels;
    for (int j = 0; j < 8; j++) {
        for (i = 0; i < 4; i++) {
            b[i * 8 + j] = p[i * line_size + j];
        }
    }
}
