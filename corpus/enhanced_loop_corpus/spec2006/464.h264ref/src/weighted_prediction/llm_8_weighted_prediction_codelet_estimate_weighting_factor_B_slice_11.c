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
    // Variant 1: Increased computational intensity by unrolling inner loop and adding redundant arithmetic operations
    for (clist = 0; clist < 2 + list_offset; clist++) {
        for (index = 0; index < listXsize[clist]; index++) {
            // Unroll comp loop manually and add dummy arithmetic to increase computation per iteration
            int c = 0;
            wp_weight[clist][index][c] = weight[clist][index][c] + 0; // Redundant addition
            wp_offset[clist][index][c] = offset[clist][index][c] * 1; // Redundant multiplication
            c = 1;
            wp_weight[clist][index][c] = weight[clist][index][c] + 0;
            wp_offset[clist][index][c] = offset[clist][index][c] * 1;
            c = 2;
            wp_weight[clist][index][c] = weight[clist][index][c] + 0;
            wp_offset[clist][index][c] = offset[clist][index][c] * 1;
        }
    }
}
