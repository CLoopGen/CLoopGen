#include <stdio.h>

#include <inttypes.h>

extern int ***wp_weight;
extern int ***wp_offset;
extern int luma_log_weight_denom;
extern int chroma_log_weight_denom;
extern int listXsize[6];
extern int _usr_index;
extern int list_offset;
extern int clist;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
for (clist = 0; clist < 2 + list_offset; clist++) {
    for (index = 0; index < listXsize[clist]; index++) {
        int luma_weight = 1 << luma_log_weight_denom;
        int chroma_weight = 1 << chroma_log_weight_denom;
        wp_weight[clist][index][0] = luma_weight;
        wp_weight[clist][index][1] = chroma_weight;
        wp_weight[clist][index][2] = chroma_weight;
        wp_offset[clist][index][0] = 0;
        wp_offset[clist][index][1] = 0;
        wp_offset[clist][index][2] = 0;
    }
}
}
