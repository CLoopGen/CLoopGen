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
    // Variant 2: Indirect Memory Access via Index Mapping
    // Use an explicit index array to simulate indirect access, mimicking irregular or gathered patterns.
    // Although data layout is regular, access through an indirection table changes the memory access behavior.
    const int comp_index_map[3] = {2, 0, 1}; // Reorder access: 2, then 0, then 1

    for (clist = 0; clist < 2 + list_offset; clist++) {
        for (index = 0; index < listXsize[clist]; index++) {
            for (int m = 0; m < 3; m++) {
                comp = comp_index_map[m]; // Indirect indexing
                wp_weight[clist][index][comp] = weight[clist][index][comp];
                wp_offset[clist][index][comp] = offset[clist][index][comp];
            }
        }
    }
}
