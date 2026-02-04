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
    int i;
    alen = 0;
    for (i = blocknum - 1; i >= 0; i--) {
        int width = blocks[i].rcol - blocks[i].lcol + 1;
        alen += (width > 0) ? width : 0;
    }
}
