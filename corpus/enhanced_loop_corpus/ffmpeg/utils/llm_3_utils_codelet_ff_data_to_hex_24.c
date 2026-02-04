#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *buff;
extern  uint8_t *src;
extern int s;
extern int i;
extern  char *hex_table;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every second element first, then the others (interleaved stride)
    // First pass: process even indices with stride 2
    int i2;
    for (i2 = 0; i2 < s; i2 += 2) {
        buff[i2 * 2] = hex_table[src[i2] >> 4];
        buff[i2 * 2 + 1] = hex_table[src[i2] & 15];
    }
    // Second pass: process odd indices with stride 2
    for (i2 = 1; i2 < s; i2 += 2) {
        buff[i2 * 2] = hex_table[src[i2] >> 4];
        buff[i2 * 2 + 1] = hex_table[src[i2] & 15];
    }
}
