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
    // Variant 1: Increased computational intensity by unrolling the loop and reducing trip count
    int n = new_palette.nentries;
    int i = 0;

    // Loop unrolling by a factor of 2 to reduce loop overhead and increase arithmetic operations per iteration
    for (; i < n - 1; i += 2) {
        png_sPLT_entryp pp1 = new_palette.entries + i;
        png_sPLT_entryp pp2 = new_palette.entries + i + 1;

        if (new_palette.depth == 8) {
            // Process two entries at once
            pp1->red     = *entry_start++;
            pp1->green   = *entry_start++;
            pp1->blue    = *entry_start++;
            pp1->alpha   = *entry_start++;
            pp1->frequency = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
            entry_start += 2;

            pp2->red     = *entry_start++;
            pp2->green   = *entry_start++;
            pp2->blue    = *entry_start++;
            pp2->alpha   = *entry_start++;
            pp2->frequency = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
            entry_start += 2;
        } else {
            pp1->red = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
            entry_start += 2;
            pp1->green = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
            entry_start += 2;
            pp1->blue = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
            entry_start += 2;
            pp1->alpha = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
            entry_start += 2;
            pp1->frequency = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
            entry_start += 2;

            pp2->red = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
            entry_start += 2;
            pp2->green = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
            entry_start += 2;
            pp2->blue = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
            entry_start += 2;
            pp2->alpha = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
            entry_start += 2;
            pp2->frequency = ((png_uint_16)(((unsigned int)(*(entry_start)) << 8) + ((unsigned int)(*((entry_start) + 1)))));
            entry_start += 2;
        }
    }

    // Handle remaining element if nentries is odd
    for (; i < new_palette.nentries; i++) {
        pp = new_palette.entries + i;
        if (new_palette.depth == 8) {
            pp->red = *entry_start++;
            pp->green = *entry_start++;
            pp->blue = *entry_start++;
            pp->alpha = *entry_start++;
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
