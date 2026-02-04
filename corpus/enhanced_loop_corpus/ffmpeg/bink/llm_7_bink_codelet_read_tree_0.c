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
    tree->syms[0] = 0;
    for (i = 1; i < 16; i++) {
        tree->syms[i] = tree->syms[i-1] + 1;
    }
}
