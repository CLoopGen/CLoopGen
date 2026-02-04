#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef struct png_color_struct {
    png_byte red;
    png_byte green;
    png_byte blue;
} png_color;

typedef png_color *png_colorp;

extern png_colorp palette;
extern int num_palette;
extern int color_inc;
extern int i;
extern int v;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access
    // Instead of accessing palette sequentially, write with a stride of 2 (every other element),
    // then handle the second pass for remaining elements if needed.
    // Here we assume num_palette is even for simplicity.
    int n = num_palette;
    int half_n = n / 2;
    for (i = 0, v = 0; i < half_n; i++, v += color_inc) {
        int idx1 = i * 2;           // Even indices
        int idx2 = i * 2 + 1;       // Odd indices
        palette[idx1].red     = (png_byte)(v & 255);
        palette[idx1].green   = (png_byte)(v & 255);
        palette[idx1].blue    = (png_byte)(v & 255);
        
        palette[idx2].red     = (png_byte)((v + color_inc) & 255);
        palette[idx2].green   = (png_byte)((v + color_inc) & 255);
        palette[idx2].blue    = (png_byte)((v + color_inc) & 255);
    }
    // If num_palette is odd, handle last element
    if (n % 2 == 1) {
        int last_idx = n - 1;
        palette[last_idx].red     = (png_byte)(v & 255);
        palette[last_idx].green   = (png_byte)(v & 255);
        palette[last_idx].blue    = (png_byte)(v & 255);
    }
}
