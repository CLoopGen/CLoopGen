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
int temp_alen = 0;
for (currblock = 0; currblock < blocknum; currblock++) {
    temp_alen += blocks[currblock].rcol - blocks[currblock].lcol + 1;
}
alen += temp_alen;
}
