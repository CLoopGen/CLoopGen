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
    png_sPLT_entryp base_entry = new_palette.entries;
    png_bytep local_start = entry_start;
    for (i = 0; i < new_palette.nentries; i++) {
        png_sPLT_entryp current = base_entry + i;
        if (new_palette.depth == 8) {
            current->red = *local_start++;
            current->green = *local_start++;
            current->blue = *local_start++;
            current->alpha = *local_start++;
        } else {
            current->red = ((png_uint_16)(((unsigned int)(*(local_start)) << 8) + (*(local_start + 1))));
            local_start += 2;
            current->green = ((png_uint_16)(((unsigned int)(*(local_start)) << 8) + (*(local_start + 1))));
            local_start += 2;
            current->blue = ((png_uint_16)(((unsigned int)(*(local_start)) << 8) + (*(local_start + 1))));
            local_start += 2;
            current->alpha = ((png_uint_16)(((unsigned int)(*(local_start)) << 8) + (*(local_start + 1))));
            local_start += 2;
        }
        current->frequency = ((png_uint_16)(((unsigned int)(*(local_start)) << 8) + (*(local_start + 1))));
        local_start += 2;
    }
    entry_start = local_start;
}
