#include <stdio.h>

#include <inttypes.h>

extern int ***wp_weight;
extern int ***wp_offset;
extern int listXsize[6];
extern int _usr_index;
extern int comp;
extern int list_offset;
extern int weight[6][15][3];
extern int offset[6][15][3];
extern int clist;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Access arrays with a stride of 2 in the 'index' dimension, then handle remainder
    for (clist = 0; clist < 2 + list_offset; clist++) {
        // First pass: strided access (every 2nd element)
        for (index = 0; index < listXsize[clist]; index += 2) {
            for (comp = 0; comp < 3; comp++) {
                wp_weight[clist][index][comp] = weight[clist][index][comp];
                wp_offset[clist][index][comp] = offset[clist][index][comp];
            }
        }
        // Second pass: handle odd indices (remainder)
        for (index = 1; index < listXsize[clist]; index += 2) {
            for (comp = 0; comp < 3; comp++) {
                wp_weight[clist][index][comp] = weight[clist][index][comp];
                wp_offset[clist][index][comp] = offset[clist][index][comp];
            }
        }
    }
}
