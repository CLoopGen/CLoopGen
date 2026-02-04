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
    int *lw = &wp_weight[clist][0][0];
    int *co = &wp_offset[clist][0][0];
    int luma_shift = luma_log_weight_denom;
    int chroma_shift = chroma_log_weight_denom;
    for (index = 0; index < listXsize[clist]; index++) {
        lw[3*index + 0] = 1 << luma_shift;
        lw[3*index + 1] = 1 << chroma_shift;
        lw[3*index + 2] = 1 << chroma_shift;
        co[3*index + 0] = 0;
        co[3*index + 1] = 0;
        co[3*index + 2] = 0;
    }
}
}
