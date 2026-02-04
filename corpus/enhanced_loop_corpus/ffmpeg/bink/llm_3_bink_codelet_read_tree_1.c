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
    // Variant 2: Indirect memory access via index remapping
    // Use a fixed indirect access pattern: reorder traversal using an index map
    static const int index_map[16] = {0, 2, 4, 6, 8, 10, 12, 14, 1, 3, 5, 7, 9, 11, 13, 15};
    len = -1;
    for (i = 0; i < 16 && len < 15; i++) {
        int idx = index_map[i]; // Indirect access through mapping
        if (!tmp1[idx])
            tree->syms[++len] = idx;
    }
}
