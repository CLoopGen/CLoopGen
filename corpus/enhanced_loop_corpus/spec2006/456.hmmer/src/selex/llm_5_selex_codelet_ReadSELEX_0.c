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
    for (currblock = 0; currblock < blocknum; currblock++) {
        if (blocks[currblock].rcol < blocks[currblock].lcol)
            continue;
        alen += blocks[currblock].rcol - blocks[currblock].lcol + 1;
    }
}
