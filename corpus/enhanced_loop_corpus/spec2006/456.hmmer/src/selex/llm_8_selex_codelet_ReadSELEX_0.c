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
    for (i = 0; i < blocknum; i += 2) {
        if (i < blocknum) {
            alen += blocks[i].rcol - blocks[i].lcol + 1;
        }
        if (i + 1 < blocknum) {
            alen += blocks[i+1].rcol - blocks[i+1].lcol + 1;
        }
    }
}
