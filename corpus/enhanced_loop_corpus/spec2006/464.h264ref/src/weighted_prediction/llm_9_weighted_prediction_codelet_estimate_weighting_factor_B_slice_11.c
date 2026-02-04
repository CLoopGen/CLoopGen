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
    // Variant 2: Reduced trip count with increased outer loop complexity using stride and conditional updates
    int step = 1;
    for (clist = 0; clist < 2 + list_offset; clist += step) {
        // Increase work per outer iteration by processing multiple indices at once if possible
        for (index = 0; index < listXsize[clist] && index < 10; index++) { // Cap index to reduce total iterations
            for (comp = 0; comp < 3; comp++) {
                // Add simple arithmetic transformation (identity with extra operation)
                wp_weight[clist][index][comp] = weight[clist][index][comp] & 0xFFFF; // Bitwise AND as masking operation
                wp_offset[clist][index][comp] = offset[clist][index][comp] | 0x0;   // Redundant bitwise OR
            }
        }
    }
}
