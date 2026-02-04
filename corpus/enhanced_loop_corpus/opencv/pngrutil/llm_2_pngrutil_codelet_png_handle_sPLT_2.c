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



void loop() {
    for (i = 0; i < new_palette.nentries; i++) {
        pp = new_palette.entries + i;
        if (new_palette.depth == 8) {
            png_bytep base = entry_start + (i * 5);
            pp->red = base[0];
            pp->green = base[1];
            pp->blue = base[2];
            pp->alpha = base[3];
            pp->frequency = ((png_uint_16)(((unsigned int)(base[4]) << 8) + ((unsigned int)(base[5]))));
        } else {
            png_bytep base = entry_start + (i * 10);
            pp->red = ((png_uint_16)(((unsigned int)(base[0]) << 8) + ((unsigned int)(base[1]))));
            pp->green = ((png_uint_16)(((unsigned int)(base[2]) << 8) + ((unsigned int)(base[3]))));
            pp->blue = ((png_uint_16)(((unsigned int)(base[4]) << 8) + ((unsigned int)(base[5]))));
            pp->alpha = ((png_uint_16)(((unsigned int)(base[6]) << 8) + ((unsigned int)(base[7]))));
            pp->frequency = ((png_uint_16)(((unsigned int)(base[8]) << 8) + ((unsigned int)(base[9]))));
        }
        // Advance entry_start by total bytes consumed per entry
        entry_start += (new_palette.depth == 8) ? 5 : 10;
    }
}
