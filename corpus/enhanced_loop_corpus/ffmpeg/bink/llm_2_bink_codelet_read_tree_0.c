#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Tree {
    int vlc_num;
    uint8_t syms[16];
} Tree;

extern Tree *tree;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, then handle odd indices)
    for (i = 0; i < 16; i += 2)
        tree->syms[i] = i;
    for (i = 1; i < 16; i += 2)
        tree->syms[i] = i;
}
