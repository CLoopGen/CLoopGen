#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef char *png_charp;

typedef unsigned short png_uint_16;

typedef struct png_sPLT_entry_struct {
    png_uint_16 red;
    png_uint_16 green;
    png_uint_16 blue;
    png_uint_16 alpha;
    png_uint_16 frequency;
} png_sPLT_entry;

typedef png_sPLT_entry *png_sPLT_entryp;

typedef int png_int_32;

typedef struct png_sPLT_struct {
    png_charp name;
    png_byte depth;
    png_sPLT_entryp entries;
    png_int_32 nentries;
} png_sPLT_t;

extern png_bytep entry_start;
extern png_sPLT_t new_palette;
extern png_sPLT_entryp pp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < new_palette.nentries; i++) {
    pp = new_palette.entries + i;
    int is_depth_8 = (new_palette.depth == 8);

    // Unconditionally handle frequency at the end
    // But interleave control with simplified branching logic

    if (is_depth_8) {
        pp->red = *entry_start++;
        pp->green = *entry_start++;
        pp->blue = *entry_start++;
        pp->alpha = *entry_start++;
    } else {
        // Combine repeated pattern into a macro-like block using temporary pointers
        png_bytep p = entry_start;
        pp->red = ((png_uint_16)(((unsigned int)p[0] << 8) + p[1]));
        pp->green = ((png_uint_16)(((unsigned int)p[2] << 8) + p[3]));
        pp->blue = ((png_uint_16)(((unsigned int)p[4] << 8) + p[5]));
        pp->alpha = ((png_uint_16)(((unsigned int)p[6] << 8) + p[7]));
        entry_start += 8;
    }

    // Always read frequency as 16-bit
    png_bytep freq_ptr = entry_start;
    pp->frequency = ((png_uint_16)(((unsigned int)freq_ptr[0] << 8) + freq_ptr[1]));
    entry_start += 2;
}
}
