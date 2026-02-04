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
            for (int comp = 0; comp < 3; comp++) {
                if (comp == 0) {
                    wp_weight[clist][index][comp] = 1 << luma_log_weight_denom;
                } else {
                    wp_weight[clist][index][comp] = 1 << chroma_log_weight_denom;
                }
                wp_offset[clist][index][comp] = 0;
            }
        }
    }
}
