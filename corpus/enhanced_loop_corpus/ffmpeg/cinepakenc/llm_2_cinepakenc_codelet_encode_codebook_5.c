#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *codebook;
extern int size;
extern unsigned char *buf;
extern int x;
extern int y;
extern int ret;
extern int entry_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing codebook in row-major order (y + x * entry_size),
    // we reverse the traversal to column-major (x + y * size), creating a strided access pattern.
    // This changes spatial locality and may affect cache performance.
    for (y = 0; y < entry_size; y++)
        for (x = 0; x < size; x++)
            buf[ret++] = codebook[x + y * size] ^ (y >= 4 ? 128 : 0);
}
