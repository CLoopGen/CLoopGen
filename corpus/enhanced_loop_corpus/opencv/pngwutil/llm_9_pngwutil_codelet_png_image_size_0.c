#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef size_t png_alloc_size_t;

extern png_uint_32 h;
extern png_uint_32 w;
extern unsigned int pd;
extern png_alloc_size_t cb_base;
extern int pass;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cb_base = 0, pass = 0; pass <= 6; pass += 2) {
    png_uint_32 shift_x = (pass > 1) ? (7 - pass) >> 1 : 3;
    png_uint_32 shift_y = (pass > 2) ? (8 - pass) >> 1 : 3;
    png_uint_32 filter_mask_x = ((1 & pass) << (3 - ((pass + 1) >> 1))) & 7;
    png_uint_32 filter_mask_y = ((1 & ~pass) << (3 - (pass >> 1))) & 7;
    png_uint_32 pw = (w + ((1 << shift_x) - 1 - filter_mask_x)) >> shift_x;
    if (pw == 0) continue;
    png_uint_32 ph = (h + ((1 << shift_y) - 1 - filter_mask_y)) >> shift_y;
    size_t bits_per_row = (size_t)(pw) * (size_t)(pd);
    size_t bytes_per_row = (pd >= 8) ? (bits_per_row >> 3) : (bits_per_row + 7) >> 3;
    cb_base += (bytes_per_row + 1) * ph;
}
}
