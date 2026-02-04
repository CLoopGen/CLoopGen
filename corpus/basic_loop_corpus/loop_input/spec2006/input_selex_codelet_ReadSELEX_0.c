#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct block_struc {
    int lcol;
    int rcol;
};

struct block_struc *blocks;
int blocknum = 1000000;  // Approximately 1M blocks to achieve ~0.01s runtime
int currblock;
int alen;

void init_vars() {
    blocks = (struct block_struc*)calloc(blocknum, sizeof(struct block_struc));
    if (!blocks) {
        blocknum = 0;
        return;
    }
    
    for (int i = 0; i < blocknum; i++) {
        blocks[i].lcol = i * 2;
        blocks[i].rcol = i * 2 + 1 + (i % 3);  // Ensure rcol >= lcol
    }
    
    currblock = 0;
    alen = 0;
}