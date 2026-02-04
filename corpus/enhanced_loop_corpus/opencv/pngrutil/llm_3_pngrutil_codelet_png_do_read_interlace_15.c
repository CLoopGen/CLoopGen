#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef struct png_row_info_struct {
    png_uint_32 width;
    size_t rowbytes;
    png_byte color_type;
    png_byte bit_depth;
    png_byte channels;
    png_byte pixel_depth;
} png_row_info;

typedef png_row_info *png_row_infop;

typedef png_byte *png_bytep;

extern png_row_infop row_info;
extern png_bytep sp;
extern png_bytep dp;
extern unsigned int sshift;
extern unsigned int dshift;
extern unsigned int s_start;
extern unsigned int s_end;
extern int s_inc;
extern png_uint_32 i;
extern int jstop;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Memory Access Pattern
    // Access memory with a fixed stride (e.g., every 2nd element) to simulate non-unit stride access.
    // This changes spatial locality and may affect cache behavior.
    const int stride = 2;
    png_bytep sp_strided = sp;
    png_bytep dp_strided = dp;
    unsigned int local_sshift = sshift;
    unsigned int local_dshift = dshift;
    png_uint_32 effective_width = (row_info->width + stride - 1) / stride; // Adjust width for stride

    for (i = 0; i < effective_width; i++) {
        png_byte v = (png_byte)((*sp_strided >> local_sshift) & 15);
        int j;
        for (j = 0; j < jstop; j++) {
            unsigned int tmp = *dp_strided & (3855 >> (4 - local_dshift));
            tmp |= (unsigned int)(v << local_dshift);
            *dp_strided = (png_byte)(tmp & 255);
            if (local_dshift == s_end) {
                local_dshift = s_start;
                dp_strided -= stride;
            } else {
                local_dshift = (unsigned int)((int)local_dshift + s_inc);
            }
        }
        if (local_sshift == s_end) {
            local_sshift = s_start;
            sp_strided -= stride;
        } else {
            local_sshift = (unsigned int)((int)local_sshift + s_inc);
        }
    }
}
