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
    // Precompute total elements and use strided access with fixed stride of 2 across all entries
    int total_entries = new_palette.nentries;
    png_sPLT_entryp entries = new_palette.entries;
    int depth = new_palette.depth;
    int stride = (depth == 8) ? 1 : 2;

    for (i = 0; i < total_entries; i++) {
        png_sPLT_entryp current = entries + i;
        int offset = i * (depth == 8 ? 5 : 10); // Total byte offset for this entry

        if (depth == 8) {
            current->red     = *(entry_start + offset + 0);
            current->green   = *(entry_start + offset + 1);
            current->blue    = *(entry_start + offset + 2);
            current->alpha   = *(entry_start + offset + 3);
            current->frequency = (png_uint_16)(
                (((unsigned int)(entry_start[offset + 4]) << 8) +
                 ((unsigned int)(entry_start[offset + 5])))
            );
        } else {
            current->red = (png_uint_16)(
                (((unsigned int)(entry_start[offset + 0]) << 8) +
                 ((unsigned int)(entry_start[offset + 1])))
            );
            current->green = (png_uint_16)(
                (((unsigned int)(entry_start[offset + 2]) << 8) +
                 ((unsigned int)(entry_start[offset + 3])))
            );
            current->blue = (png_uint_16)(
                (((unsigned int)(entry_start[offset + 4]) << 8) +
                 ((unsigned int)(entry_start[offset + 5])))
            );
            current->alpha = (png_uint_16)(
                (((unsigned int)(entry_start[offset + 6]) << 8) +
                 ((unsigned int)(entry_start[offset + 7])))
            );
            current->frequency = (png_uint_16)(
                (((unsigned int)(entry_start[offset + 8]) << 8) +
                 ((unsigned int)(entry_start[offset + 9])))
            );
        }
    }

    // Update global entry_start to point past the last read byte
    entry_start += (depth == 8) ? (total_entries * 5) : (total_entries * 10);
}
