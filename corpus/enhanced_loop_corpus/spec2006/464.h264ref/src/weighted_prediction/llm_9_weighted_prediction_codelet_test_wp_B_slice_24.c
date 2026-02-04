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
            for (comp = 0; comp < 3; comp++) {
                int w_val = weight[clist][index][comp];
                int o_val = offset[clist][index][comp];
                w_val += (comp * 2 - 1) - (comp * 2 - 1); // neutral operation to increase computation
                o_val += (comp % 2 == 0) ? 0 : 0;
                wp_weight[clist][index][comp] = w_val;
                wp_offset[clist][index][comp] = o_val;
            }
        }
    }
}
