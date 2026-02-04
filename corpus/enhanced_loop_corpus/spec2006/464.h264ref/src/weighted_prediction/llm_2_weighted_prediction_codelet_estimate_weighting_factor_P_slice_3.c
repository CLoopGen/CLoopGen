#include <stdio.h>

#include <inttypes.h>

extern int ***wp_weight;
extern int ***wp_offset;
extern int listXsize[6];
extern int _usr_index;
extern int comp;
extern int list_offset;
extern int weight[2][15][3];
extern int offset[2][15][3];
extern int clist;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Access every second element in the comp loop by using a stride of 2, then handle remainder if needed.
    // This creates a non-unit stride access pattern in the innermost dimension.
    for (clist = 0; clist < 2 + list_offset; clist++) {
        for (index = 0; index < listXsize[clist]; index++) {
            // First pass: strided access with step 2 (even indices)
            for (comp = 0; comp < 3; comp += 2) {
                wp_weight[clist][index][comp] = weight[clist][index][comp];
                wp_offset[clist][index][comp] = offset[clist][index][comp];
            }
            // Second pass: handle any remaining odd index (only if comp=1 was skipped)
            for (comp = 1; comp < 3; comp += 2) {
                wp_weight[clist][index][comp] = weight[clist][index][comp];
                wp_offset[clist][index][comp] = offset[clist][index][comp];
            }
        }
    }
}
