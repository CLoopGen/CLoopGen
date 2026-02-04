#include <stdio.h>

#include <inttypes.h>

extern int ***wp_weight;
extern int ***wp_offset;
extern int listXsize[6];
extern int _usr_index;
extern int comp;
extern int list_offset;
extern int weight[2][15][3];
extern int offset[2][15][3];
extern int clist;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Reduce computational intensity by unrolling and decreasing effective trip count
    for (clist = 0; clist < 2 + list_offset; clist += 1) {
        // Process two iterations at a time if possible, reducing loop overhead
        int limit = listXsize[clist] & ~1; // Round down to even number
        for (index = 0; index < limit; index += 2) {
            for (comp = 0; comp < 3; comp++) {
                // First index
                wp_weight[clist][index][comp] = weight[clist][index][comp];
                wp_offset[clist][index][comp] = offset[clist][index][comp];
                // Second index
                wp_weight[clist][index+1][comp] = weight[clist][index+1][comp];
                wp_offset[clist][index+1][comp] = offset[clist][index+1][comp];
            }
        }
        // Handle remaining element if listXsize[clist] is odd
        if (index < listXsize[clist]) {
            for (comp = 0; comp < 3; comp++) {
                wp_weight[clist][index][comp] = weight[clist][index][comp];
                wp_offset[clist][index][comp] = offset[clist][index][comp];
            }
        }
    }
}
