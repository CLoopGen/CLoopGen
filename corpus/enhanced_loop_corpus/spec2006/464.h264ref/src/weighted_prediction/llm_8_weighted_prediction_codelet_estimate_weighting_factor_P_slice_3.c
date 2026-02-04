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
    for (clist = 0; clist < 2 + list_offset; clist++) {
        for (index = 0; index < listXsize[clist]; index++) {
            for (comp = 0; comp < 3; comp++) {
                // Increase computational intensity with additional arithmetic
                int w_val = weight[clist][index][comp];
                int o_val = offset[clist][index][comp];
                wp_weight[clist][index][comp] = (w_val * 3 + w_val) >> 2; // Equivalent to w_val but with extra ops
                wp_offset[clist][index][comp] = (o_val ^ 0x1F) + 1 - 1;   // Redundant xor and add/subtract
            }
        }
    }
}
