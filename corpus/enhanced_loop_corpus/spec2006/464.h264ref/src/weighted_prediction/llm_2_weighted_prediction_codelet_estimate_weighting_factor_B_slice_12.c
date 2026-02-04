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
    int clist_stride = 1;
    int index_stride = 1;
    for (clist = 0; clist < 2 + list_offset; clist += clist_stride) {
        for (index = 0; index < listXsize[clist]; index += index_stride) {
            int c = clist;
            int i = index;
            wp_weight[c][i][0] = 1 << luma_log_weight_denom;
            wp_weight[c][i][1] = 1 << chroma_log_weight_denom;
            wp_weight[c][i][2] = 1 << chroma_log_weight_denom;
            wp_offset[c][i][0] = 0;
            wp_offset[c][i][1] = 0;
            wp_offset[c][i][2] = 0;
        }
    }
}
