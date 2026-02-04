#include <stdio.h>

#include <inttypes.h>

extern int ***wp_weight;
extern int ***wp_offset;
extern int listXsize[6];
extern int _usr_index;
extern int comp;
extern int list_offset;
extern int weight[6][15][3];
extern int offset[6][15][3];
extern int clist;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Eliminate loop-carried dependencies by unrolling and reordering independent operations
    // Each triplet of comp values is processed independently with no intra-loop dependencies
    for (clist = 0; clist < 2 + list_offset; clist++) {
        for (index = 0; index < listXsize[clist]; index++) {
            // Unroll the inner loop and make assignments independent
            wp_weight[clist][index][0] = weight[clist][index][0];
            wp_offset[clist][index][0] = offset[clist][index][0];
            wp_weight[clist][index][1] = weight[clist][index][1];
            wp_offset[clist][index][1] = offset[clist][index][1];
            wp_weight[clist][index][2] = weight[clist][index][2];
            wp_offset[clist][index][2] = offset[clist][index][2];
        }
    }
}
