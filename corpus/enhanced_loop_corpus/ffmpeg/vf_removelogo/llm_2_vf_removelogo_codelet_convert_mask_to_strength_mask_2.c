#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int linesize;
extern int w;
extern int h;
extern int x;
extern int y;
extern int current_pass;
extern int has_anything_changed;
extern uint8_t *current_pixel0;
extern uint8_t *current_pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major traversal, access pixels in a strided manner by iterating over x first (column), then y (row).
    // This changes spatial locality and may affect cache performance due to non-consecutive memory jumps.
    has_anything_changed = 0;
    for (x = 1; x < w - 1; x++) {
        current_pixel = current_pixel0 + x; // Start at column x of first processed row
        for (y = 1; y < h - 1; y++) {
            uint8_t* center = current_pixel + y * linesize;
            if (*center >= current_pass && 
                *(center + 1) >= current_pass && 
                *(center - 1) >= current_pass && 
                *(center + linesize) >= current_pass && 
                *(center - linesize) >= current_pass) {
                (*center)++;
                has_anything_changed = 1;
            }
        }
    }
}
