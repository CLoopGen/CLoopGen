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

typedef png_byte *png_bytep;

extern png_colorp palette;
extern int maximum_colors;
extern png_bytep quantize_sort;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward traversal
    // Instead of indirect access via quantize_sort and backward j decrement,
    // we precompute valid indices and traverse palette in increasing order.
    int *valid_indices = (int*)malloc(maximum_colors * sizeof(int));
    int count = 0;
    for (i = 0; i < maximum_colors; i++) {
        if ((int)quantize_sort[i] < maximum_colors) {
            valid_indices[count++] = i;
        }
    }
    // Fill invalid entries by cycling through valid palette entries from start
    int valid_idx = 0;
    for (i = 0; i < maximum_colors; i++) {
        if ((int)quantize_sort[i] >= maximum_colors) {
            if (valid_idx < count) {
                palette[i] = palette[valid_indices[valid_idx++]];
            } else {
                // Reset if we run out of valid entries
                valid_idx = 0;
                if (count > 0)
                    palette[i] = palette[valid_indices[valid_idx++]];
            }
        }
    }
    free(valid_indices);
}
