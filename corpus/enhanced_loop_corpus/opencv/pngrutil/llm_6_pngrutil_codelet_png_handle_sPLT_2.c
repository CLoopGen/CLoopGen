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
        if (new_palette.depth == 8) {
            png_byte red_val = *entry_start++;
            png_byte green_val = *entry_start++;
            png_byte blue_val = *entry_start++;
            png_byte alpha_val = *entry_start++;
            pp->red = red_val;
            pp->green = green_val;
            pp->blue = blue_val;
            pp->alpha = alpha_val;
        } else {
            pp->red = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
            entry_start += 2;
            pp->green = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
            entry_start += 2;
            pp->blue = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
            entry_start += 2;
            pp->alpha = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
            entry_start += 2;
        }
        pp->frequency = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
        entry_start += 2;
    }
}
