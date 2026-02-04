#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct spng_plte_entry {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};

unsigned char *row;
unsigned char *scanline;
uint32_t width;
uint32_t i;
unsigned char *px;
unsigned char entry;
struct spng_plte_entry *plte;

void init_vars() {
    width = 16777216;  // ~64 MB of output (width * 4), scanline is 16 MB

    row = (unsigned char *)calloc(width, 4);
    if (!row) exit(1);

    scanline = (unsigned char *)malloc(width);
    if (!scanline) exit(1);

    plte = (struct spng_plte_entry *)malloc(256 * sizeof(struct spng_plte_entry));
    if (!plte) exit(1);

    for (int idx = 0; idx < 256; idx++) {
        plte[idx].red = (uint8_t)(idx * 1.5);
        plte[idx].green = (uint8_t)(idx * 0.8);
        plte[idx].blue = (uint8_t)((255 - idx) * 0.9);
        plte[idx].alpha = (uint8_t)idx;
    }

    for (uint32_t idx = 0; idx < width; idx++) {
        scanline[idx] = (unsigned char)(idx % 256);
    }

    i = 0;
    px = NULL;
}