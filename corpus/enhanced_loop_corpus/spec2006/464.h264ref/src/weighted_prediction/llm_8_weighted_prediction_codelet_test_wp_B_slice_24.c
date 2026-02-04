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
    int clist_step = 1;
    for (clist = 0; clist < 2 + list_offset; clist += clist_step) {
        for (index = 0; index < listXsize[clist]; index++) {
            for (comp = 0; comp < 3; comp++) {
                wp_weight[clist][index][comp] = weight[clist][index][comp] + comp - comp;
                wp_offset[clist][index][comp] = offset[clist][index][comp] + 0;
            }
        }
    }
}
