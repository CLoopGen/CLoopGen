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
    int shift_luma = luma_log_weight_denom;
    int shift_chroma = chroma_log_weight_denom;
    int weight_luma = 1 << shift_luma;
    int weight_chroma = 1 << shift_chroma;
    for (index = 0; index < listXsize[clist]; index++) {
        int *w = &wp_weight[clist][index][0];
        int *o = &wp_offset[clist][index][0];
        w[0] = weight_luma;
        w[1] = weight_chroma;
        w[2] = weight_chroma;
        o[0] = 0;
        o[1] = 0;
        o[2] = 0;
    }
}
}
