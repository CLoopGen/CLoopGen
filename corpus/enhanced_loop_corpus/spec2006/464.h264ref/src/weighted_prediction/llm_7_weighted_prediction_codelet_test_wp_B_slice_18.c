#include <stdio.h>

#include <inttypes.h>

extern int ***wp_weight;
extern int ***wp_offset;
extern int listXsize[6];
extern int _usr_index;
extern int comp;
extern int default_weight;
extern int list_offset;
extern int clist;
extern int perform_wp;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    perform_wp = 0;
    // Eliminate loop-carried dependencies by unrolling the comp loop partially
    // and reorganizing condition checks to allow independent evaluation
    for (clist = 0; clist < 2 + list_offset && !perform_wp; clist++) {
        for (index = 0; index < listXsize[clist] && !perform_wp; index++) {
            // Unroll comp loop to remove loop-carried dependency on 'comp' increment
            if ((wp_weight[clist][index][0] != default_weight || wp_offset[clist][index][0] != 0) ||
                (wp_weight[clist][index][1] != default_weight || wp_offset[clist][index][1] != 0) ||
                (wp_weight[clist][index][2] != default_weight || wp_offset[clist][index][2] != 0)) {
                perform_wp = 1;
            }
        }
    }
    // No per-iteration state affects subsequent iterations beyond perform_wp,
    // thus minimizing data dependencies and enabling potential vectorization
}
