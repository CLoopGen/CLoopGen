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
    // Variant 1: Consecutive Memory Access Pattern
    // Flatten the 3D access into a single loop with consecutive memory traversal
    // assuming row-major order and known bounds (up to 15 indices in second dimension)
    int clist, index, comp;
    int max_indices = 0;
    for (int i = 0; i < 2 + list_offset; i++) {
        if (listXsize[i] > max_indices) {
            max_indices = listXsize[i];
        }
    }

    for (clist = 0; clist < 2 + list_offset; clist++) {
        for (index = 0; index < max_indices; index++) {
            int valid_index = (index < listXsize[clist]);
            for (comp = 0; comp < 3; comp++) {
                if (valid_index) {
                    wp_weight[clist][index][comp] = weight[clist][index][comp];
                    wp_offset[clist][index][comp] = offset[clist][index][comp];
                }
            }
        }
    }
}
