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
for (cb_base = 0 , pass = 0; pass <= 6; ++pass) {
    png_uint_32 pw = (((w) + (((1 << ((pass) > 1 ? (7 - (pass)) >> 1 : 3)) - 1) - (((1 & (pass)) << (3 - (((pass) + 1) >> 1))) & 7))) >> ((pass) > 1 ? (7 - (pass)) >> 1 : 3));
    if (pw > 0) {
        png_alloc_size_t row_increment = ((pd) >= 8 ? ((size_t)(pw) * (((size_t)(pd)) >> 3)) : ((((size_t)(pw) * ((size_t)(pd))) + 7) >> 3)) + 1;
        png_uint_32 ph = (((h) + (((1 << ((pass) > 2 ? (8 - (pass)) >> 1 : 3)) - 1) - (((1 & ~(pass)) << (3 - ((pass) >> 1))) & 7))) >> ((pass) > 2 ? (8 - (pass)) >> 1 : 3));
        for (png_uint_32 row = 0; row < ph; ++row) {
            cb_base += row_increment;
        }
    }
}
}
