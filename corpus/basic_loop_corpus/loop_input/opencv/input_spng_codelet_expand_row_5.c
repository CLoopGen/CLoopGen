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
    width = 16000000;  // Approximately 48MB of output data (16M * 3 bytes), scanline 16MB

    row = (unsigned char *)calloc(width * 3, sizeof(unsigned char));
    if (!row) exit(1);

    scanline = (unsigned char *)malloc(width * sizeof(unsigned char));
    if (!scanline) exit(1);

    plte = (struct spng_plte_entry *)malloc(256 * sizeof(struct spng_plte_entry));
    if (!plte) exit(1);

    for (uint32_t idx = 0; idx < width; idx++) {
        scanline[idx] = rand() % 256;
    }

    for (int idx = 0; idx < 256; idx++) {
        plte[idx].red = (idx * 7) % 256;
        plte[idx].green = (idx * 11) % 256;
        plte[idx].blue = (idx * 13) % 256;
        plte[idx].alpha = 255;
    }

    i = 0;
    px = NULL;
    entry = 0;
}