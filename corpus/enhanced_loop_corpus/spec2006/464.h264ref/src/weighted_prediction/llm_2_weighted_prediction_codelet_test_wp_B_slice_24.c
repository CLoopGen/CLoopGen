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
    // Variant 1: Strided Memory Access Pattern
    // Instead of iterating with unit stride in the innermost loop, access elements with a fixed stride of 2,
    // handling odd-sized dimensions by ensuring bounds are respected.
    int clist_max = 2 + list_offset;
    for (clist = 0; clist < clist_max; clist++) {
        int size = listXsize[clist];
        for (index = 0; index < size; index++) {
            // Unroll and stride by 2 across the comp dimension (comp=0,2), then handle comp=1 separately if needed
            if (3 > 0) wp_weight[clist][index][0] = weight[clist][index][0];
            if (3 > 2) wp_weight[clist][index][2] = weight[clist][index][2];
            if (3 > 1) wp_offset[clist][index][1] = offset[clist][index][1]; // Interleaved assignment to create strided effect
            if (3 > 0) wp_offset[clist][index][0] = offset[clist][index][0];
            if (3 > 2) wp_offset[clist][index][2] = offset[clist][index][2];
            if (3 > 1) wp_weight[clist][index][1] = weight[clist][index][1];
        }
    }
}
