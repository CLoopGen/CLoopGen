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
    uint8_t temp[16];
    for (i = 0; i < 16; i++) {
        temp[i] = i;
    }
    for (i = 0; i < 16; i++) {
        tree->syms[i] = temp[i];
    }
}
