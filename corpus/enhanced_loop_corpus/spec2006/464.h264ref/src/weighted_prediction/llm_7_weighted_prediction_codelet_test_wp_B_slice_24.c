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
    int temp_weight[3], temp_offset[3];
    for (clist = 0; clist < 2 + list_offset; clist++) {
        for (index = 0; index < listXsize[clist]; index++) {
            // Eliminate loop-carried dependencies by caching values before writing
            for (comp = 0; comp < 3; comp++) {
                temp_weight[comp] = weight[clist][index][comp];
                temp_offset[comp] = offset[clist][index][comp];
            }
            // Use cached values in separate loop to break potential RAW/WAR hazards
            for (comp = 0; comp < 3; comp++) {
                wp_weight[clist][index][comp] = temp_weight[comp];
                wp_offset[clist][index][comp] = temp_offset[comp];
            }
        }
    }
}
