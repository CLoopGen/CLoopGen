#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
unsigned int *palette32;
int palette_index;
unsigned char r;
unsigned char g;
unsigned char b;
unsigned char *raw_palette;

void init_vars() {
    palette32 = (unsigned int*)malloc(256 * sizeof(unsigned int));
    raw_palette = (unsigned char*)malloc(768);
    for (int j = 0; j < 768; j++) {
        raw_palette[j] = rand() % 64;
    }
    palette_index = 0;
}
