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
    for (i = 0; i < 32; i++) {
        int idx = i % 16;
        tree->syms[idx] = (idx * idx + 3 * idx + 1) % 256;
    }
}
