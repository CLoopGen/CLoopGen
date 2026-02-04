#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Tree {
    int vlc_num;
    uint8_t syms[16];
} Tree;

extern Tree *tree;
extern uint8_t tmp1[16];
extern int i;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16 && len < 15; i++) {
        len += (tmp1[i] == 0);
        if (!tmp1[i]) {
            tree->syms[len] = i;
        }
    }
}
