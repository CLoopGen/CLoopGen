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
    // Variant 2: Indirect Memory Access Pattern via Index Array
    // Use an auxiliary index array to access blocks indirectly
    int indices[blocknum];
    for (int i = 0; i < blocknum; i++) {
        indices[i] = i;  // Identity mapping, but enables indirect access
    }
    alen = 0;
    for (int i = 0; i < blocknum; i++) {
        int idx = indices[i];  // Indirect access through index array
        alen += blocks[idx].rcol - blocks[idx].lcol + 1;
    }
}
