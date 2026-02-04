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
    // Variant 2: Indirect (Indexed) Memory Access via Index Array
    // Use an auxiliary index array to access palette in non-sequential order.
    // Simulate indirect access by writing in reverse order using computed indices.
    int* indices = (int*)malloc(num_palette * sizeof(int));
    if (!indices) return; // Handle malloc failure

    // Initialize index map: reverse order access
    for (int j = 0; j < num_palette; j++) {
        indices[j] = num_palette - 1 - j;
    }

    for (i = 0, v = 0; i < num_palette; i++, v += color_inc) {
        int mapped_index = indices[i]; // Indirect access index
        palette[mapped_index].red     = (png_byte)(v & 255);
        palette[mapped_index].green   = (png_byte)(v & 255);
        palette[mapped_index].blue    = (png_byte)(v & 255);
    }

    free(indices);
}
