#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int rgn_nr_blocks;
    int rgn_blocks;
} region;

extern int n_basic_blocks;
extern region *rgn_table;
extern int *rgn_bb_table;
extern int *block_to_bb;
extern int *containing_rgn;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < n_basic_blocks; i++) {
    for (j = 0; j < 1; j++) {
        rgn_bb_table[i] = i;
        (rgn_table[i].rgn_nr_blocks) = 1;
        (rgn_table[i].rgn_blocks) = i;
        (containing_rgn[i]) = i;
        (block_to_bb[i]) = 0;
    }
}
}
