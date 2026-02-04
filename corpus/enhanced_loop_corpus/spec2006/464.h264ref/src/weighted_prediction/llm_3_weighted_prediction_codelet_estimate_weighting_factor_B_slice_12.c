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
    // Use reverse iteration to modify memory access pattern (strided in reverse)
    for (clist = 1 + list_offset; clist >= 0; clist--) {
        for (index = listXsize[clist] - 1; index >= 0; index--) {
            wp_weight[clist][index][0] = 1 << luma_log_weight_denom;
            wp_weight[clist][index][1] = 1 << chroma_log_weight_denom;
            wp_weight[clist][index][2] = 1 << chroma_log_weight_denom;
            wp_offset[clist][index][0] = 0;
            wp_offset[clist][index][1] = 0;
            wp_offset[clist][index][2] = 0;
        }
    }
}
