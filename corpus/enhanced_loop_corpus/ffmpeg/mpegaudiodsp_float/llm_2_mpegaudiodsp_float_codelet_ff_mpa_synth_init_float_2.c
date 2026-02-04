#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering indices to access memory sequentially
    MPA_INT *base = window + 512 + 128;
    for (i = 0; i < 8; i++) {
        MPA_INT *src_base = window + 64 * i + 48;
        for (j = 0; j < 16; j++) {
            base[16 * i + j] = src_base[-j]; // Still reverse within block, but base per i
        }
    }
}
