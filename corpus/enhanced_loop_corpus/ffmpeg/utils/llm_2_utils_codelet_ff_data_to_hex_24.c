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
    // Variant 1: Consecutive memory access with unrolled loop (2x unrolling) to promote sequential writes
    int i4 = (s / 2) * 2;  // Round down to even number for safe unrolling
    for (i = 0; i < i4; i += 2) {
        uint8_t val1 = src[i];
        uint8_t val2 = src[i + 1];
        buff[i * 2]       = hex_table[val1 >> 4];
        buff[i * 2 + 1]   = hex_table[val1 & 15];
        buff[i * 2 + 2]   = hex_table[val2 >> 4];
        buff[i * 2 + 3]   = hex_table[val2 & 15];
    }
    // Handle remaining element if s is odd
    if (i < s) {
        buff[i * 2] = hex_table[src[i] >> 4];
        buff[i * 2 + 1] = hex_table[src[i] & 15];
    }
}
