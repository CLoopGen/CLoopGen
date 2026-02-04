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
    // Variant 1: Strided Memory Access Pattern
    // Access every second block in a strided manner, then handle remainder
    alen = 0;
    int i;
    for (i = 0; i < blocknum; i += 2) {
        alen += blocks[i].rcol - blocks[i].lcol + 1;
    }
    for (i = 1; i < blocknum; i += 2) {
        alen += blocks[i].rcol - blocks[i].lcol + 1;
    }
}
