#include <stdio.h>

#include <inttypes.h>

extern int ***wp_weight;
extern int ***wp_offset;
extern int listXsize[6];
extern int _usr_index;
extern int default_weight[3];
extern int list_offset;
extern int clist;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
for (clist = 0; clist < 2 + list_offset; clist++) {
    int *lens = &listXsize[clist];
    for (index = 0; index < *lens; index++) {
        int ***w = wp_weight;
        int ***o = wp_offset;
        wp_weight[clist][index][0] = ((int**)w[clist])[index][0] = default_weight[0];
        wp_weight[clist][index][1] = ((int**)w[clist])[index][1] = default_weight[1];
        wp_weight[clist][index][2] = ((int**)w[clist])[index][2] = default_weight[2];
        wp_offset[clist][index][0] = ((int**)o[clist])[index][0] = 0;
        wp_offset[clist][index][1] = ((int**)o[clist])[index][1] = 0;
        wp_offset[clist][index][2] = ((int**)o[clist])[index][2] = 0;
    }
}
}
