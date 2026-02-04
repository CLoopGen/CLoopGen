#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef char *png_charp;
typedef unsigned short png_uint_16;
typedef int png_int_32;

typedef struct png_sPLT_entry_struct {
    png_uint_16 red;
    png_uint_16 green;
    png_uint_16 blue;
    png_uint_16 alpha;
    png_uint_16 frequency;
} png_sPLT_entry;

typedef png_sPLT_entry *png_sPLT_entryp;

typedef struct png_sPLT_struct {
    png_charp name;
    png_byte depth;
    png_sPLT_entryp entries;
    png_int_32 nentries;
} png_sPLT_t;

png_bytep entry_start;
png_sPLT_t new_palette;
png_sPLT_entryp pp;
int i;

void init_vars() {
    const size_t target_size = 16 << 20; // ~16 MB for ~0.01 sec runtime
    const int element_size_16bit = 10;   // 4×2 (RGBA) + 2 (freq) = 10 bytes per entry when depth != 8
    const int element_size_8bit = 5;     // 4×1 (RGBA) + 1×2 (freq) = 5 bytes per entry when depth == 8

    // Use 16-bit depth to maximize data consumption per entry
    new_palette.depth = 16;
    new_palette.nentries = target_size / element_size_16bit;

    // Allocate entries
    new_palette.entries = (png_sPLT_entryp)calloc(new_palette.nentries, sizeof(png_sPLT_entry));
    if (!new_palette.entries) exit(1);

    // Allocate and fill entry_start buffer: each entry needs 4×2 (RGBA) + 1×2 (freq) = 10 bytes
    size_t buffer_size = new_palette.nentries * element_size_16bit;
    entry_start = (png_bytep)malloc(buffer_size);
    if (!entry_start) exit(1);

    for (size_t idx = 0; idx < buffer_size; idx++) {
        entry_start[idx] = (png_byte)(idx & 0xFF);
    }

    pp = NULL;
    i = 0;
}