#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Tree {
    int vlc_num;
    uint8_t syms[16];
} Tree;

Tree *tree;
uint8_t tmp1[16];
int i;
int len;

void init_vars() {
    tree = (Tree*)malloc(sizeof(Tree));
    if (!tree) {
        exit(1);
    }
    tree->vlc_num = 0;
    for (int j = 0; j < 16; j++) {
        tree->syms[j] = 0;
        tmp1[j] = (j % 2 == 0) ? 1 : 0;
    }
    i = 0;
    len = 0;
}