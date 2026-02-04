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
    // Variant 2: Reduced computational intensity with simplified data access and increased arithmetic fusion
    // Merge byte reads into fewer expressions and minimize pointer arithmetic

    for (i = 0; i < new_palette.nentries; i++) {
        pp = new_palette.entries + i;
        const png_bytep current = entry_start;

        if (new_palette.depth == 8) {
            // Compact sequential access without intermediate increments
            pp->red       = current[0];
            pp->green     = current[1];
            pp->blue      = current[2];
            pp->alpha     = current[3];
            pp->frequency = (png_uint_16)((current[4] << 8) | current[5]);
            entry_start += 6;  // Skip all consumed bytes at once
        } else {
            // Combine high/low byte reconstruction in fewer operations
            pp->red       = (png_uint_16)((current[0] << 8) | current[1]);
            pp->green     = (png_uint_16)((current[2] << 8) | current[3]);
            pp->blue      = (png_uint_16)((current[4] << 8) | current[5]);
            pp->alpha     = (png_uint_16)((current[6] << 8) | current[7]);
            pp->frequency = (png_uint_16)((current[8] << 8) | current[9]);
            entry_start += 10; // Advance by full 10-byte block
        }
    }
}
