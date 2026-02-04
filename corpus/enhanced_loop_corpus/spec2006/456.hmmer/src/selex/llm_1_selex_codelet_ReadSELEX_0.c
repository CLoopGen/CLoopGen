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
for (int i = 0; i < blocknum; i++) {
    for (int j = 0; j <= (blocks[i].rcol - blocks[i].lcol); j++) {
        alen++;
    }
}
}
