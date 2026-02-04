#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;
extern unsigned int gray;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decreased effective loop depth by completely unrolling the loop under assumption of small known row_width
    // Using recursion-like simulation with labels and goto avoided; instead, assume bounded small width and unroll conditionally
    // Since row_width is runtime variable, full unrolling not possible, but simulate partial unrolling via nested for structure collapse

    // Instead: Transform into dual-phase loop with split iteration (reducing logical depth via elimination of branching in data path)
    // This variant reduces nesting potential by fusing operations across iterations conceptually, though still one loop

    // Alternate mutation: remove all nesting and ensure flat single loop — but that's original.
    // So instead, apply loop fusion idea: combine multiple steps per iteration to decrease effective iteration count

    png_uint_32 limit = row_width / 2;
    png_uint_32 remainder = row_width % 2;

    // Process two elements per iteration where possible (loop jamming / strip mining)
    for (i = 0; i < limit; i++) {
        // First element
        if ((*sp & 255U) == gray)
            *dp-- = 0;
        else
            *dp-- = 255;
        *dp-- = *sp--;

        // Second element
        if ((*sp & 255U) == gray)
            *dp-- = 0;
        else
            *dp-- = 255;
        *dp-- = *sp--;
    }

    // Handle leftover element
    for (i = 0; i < remainder; i++) {
        if ((*sp & 255U) == gray)
            *dp-- = 0;
        else
            *dp-- = 255;
        *dp-- = *sp--;
    }
}
