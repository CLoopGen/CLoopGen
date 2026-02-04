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
    // Variant 2: Strided memory access with reversed and interleaved component update
    // Instead of processing all components per index, we stride across color components first,
    // then indices. This creates a strided access pattern over wp_weight and wp_offset.

    for (clist = 0; clist < 2 + list_offset; clist++) {
        int size = listXsize[clist];
        int comp;

        // Process components in reverse order (2, 1, 0) and stride across indices
        for (comp = 2; comp >= 0; comp--) {
            for (index = 0; index < size; index++) {
                if (comp == 0) {
                    wp_weight[clist][index][comp] = 1 << luma_log_weight_denom;
                    wp_offset[clist][index][comp] = 0;
                } else {
                    wp_weight[clist][index][comp] = 1 << chroma_log_weight_denom;
                    wp_offset[clist][index][comp] = 0;
                }
            }
        }
    }
}
