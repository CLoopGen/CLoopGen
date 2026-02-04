#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Tree {
    int vlc_num;
    uint8_t syms[16];
} Tree;

Tree *tree;
int i;

void init_vars() {
    tree = (Tree*)malloc(sizeof(Tree));
    if (!tree) {
        exit(1);
    }
    tree->vlc_num = 0;
}