#include <stdio.h>

#include <inttypes.h>

struct block_struc {
    int lcol;
    int rcol;
};


extern struct block_struc *blocks;
extern int blocknum;
extern int currblock;
extern int alen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_lcol = 0;
    for (currblock = 0; currblock < blocknum; currblock++) {
        int delta = blocks[currblock].rcol - prev_lcol + 1;
        alen += delta;
        prev_lcol = blocks[currblock].lcol;
    }
}
