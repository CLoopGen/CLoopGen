#include <stdio.h>

#include <inttypes.h>

extern int ***wp_weight;
extern int ***wp_offset;
extern int listXsize[6];
extern int _usr_index;
extern int comp;
extern int default_weight;
extern int list_offset;
extern int clist;
extern int perform_wp;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
for (clist = 0; clist < 2 + list_offset; clist++) {
    for (index = 0; index < listXsize[clist]; index++) {
        comp = 0;
        if (wp_weight[clist][index][comp] != default_weight || wp_offset[clist][index][comp] != 0) {
            perform_wp = 1;
            break;
        }
        comp = 1;
        if (wp_weight[clist][index][comp] != default_weight || wp_offset[clist][index][comp] != 0) {
            perform_wp = 1;
            break;
        }
        comp = 2;
        if (wp_weight[clist][index][comp] != default_weight || wp_offset[clist][index][comp] != 0) {
            perform_wp = 1;
            break;
        }
    }
    if (perform_wp == 1)
        break;
}
}
