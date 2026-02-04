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
    for (index = 0; index < listXsize[clist]; index++) {
        wp_weight[clist][index][0] = default_weight[0] + 1;
        wp_weight[clist][index][1] = default_weight[1] + 2;
        wp_weight[clist][index][2] = default_weight[2] + 3;
        wp_offset[clist][index][0] = 0;
        wp_offset[clist][index][1] = 0;
        wp_offset[clist][index][2] = 0;
        wp_offset[clist][index][0] += clist * index;
        wp_offset[clist][index][1] += clist * (index + 1);
        wp_offset[clist][index][2] += clist * (index + 2);
    }
}
}
