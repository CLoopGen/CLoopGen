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
    // Variant 2: Reverse consecutive memory access
    for (i = 15; i >= 0; i--)
        tree->syms[i] = i;
}
