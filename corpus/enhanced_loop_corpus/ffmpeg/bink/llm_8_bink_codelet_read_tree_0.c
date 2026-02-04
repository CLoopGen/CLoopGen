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
    int step = 2;
    for (i = 0; i < 16; i += step) {
        tree->syms[i] = i;
        if (i + 1 < 16)
            tree->syms[i + 1] = i + 1;
    }
}
