#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char UINT8;

extern UINT8 bits[33];
extern int bit_pos[33];
extern int p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic for bits and bit_pos
    int *pos_ptr = &bit_pos[1];
    UINT8 *bits_ptr = &bits[1];
    int current_p = p;
    for (i = 0; i < 32; i++) {
        pos_ptr[i] = current_p;
        current_p += bits_ptr[i];
    }
    p = current_p;
}
