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
    // Eliminate loop-carried dependencies by reordering and introducing temporary accumulators
    int temp_weight[3];
    int temp_offset[3];
    for (clist = 0; clist < 2 + list_offset; clist++) {
        for (index = 0; index < listXsize[clist]; index++) {
            // Load all components into temporaries first (eliminate intra-loop dependencies)
            for (comp = 0; comp < 3; comp++) {
                temp_weight[comp] = weight[clist][index][comp];
                temp_offset[comp] = offset[clist][index][comp];
            }
            // Then store them, removing potential RAW/WAR hazards during store
            for (comp = 0; comp < 3; comp++) {
                wp_weight[clist][index][comp] = temp_weight[comp];
                wp_offset[clist][index][comp] = temp_offset[comp];
            }
        }
    }
}
