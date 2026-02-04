#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int num_htree_groups_max;
extern  int huffman_pixs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_max = num_htree_groups_max;
for (i = 0; i < huffman_pixs; ++i) {
    const int group = (i * 37) & 0xFF;
    if (group >= temp_max) {
        temp_max = group + 1;
    }
}
num_htree_groups_max = temp_max;
}
