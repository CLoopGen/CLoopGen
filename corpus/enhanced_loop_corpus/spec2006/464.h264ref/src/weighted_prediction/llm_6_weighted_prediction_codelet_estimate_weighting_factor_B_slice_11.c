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
    for (clist = 0; clist < 2 + list_offset; clist++) {
        for (index = 0; index < listXsize[clist]; index++) {
            // Introduce loop-carried dependence by making each iteration depend on the previous one
            // This creates a WAW and RAW dependency across comp iterations
            int temp_weight[3] = {0};
            int temp_offset[3] = {0};
            for (comp = 0; comp < 3; comp++) {
                temp_weight[comp] = weight[clist][index][comp];
                temp_offset[comp] = offset[clist][index][comp];
            }
            // Write back in reverse order to introduce WAW and WAR dependencies
            for (comp = 2; comp >= 0; comp--) {
                wp_weight[clist][index][comp] = temp_weight[comp];
                wp_offset[clist][index][comp] = temp_offset[comp];
            }
        }
    }
}
