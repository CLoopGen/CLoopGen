#include <stdio.h>

#include <inttypes.h>

extern int ***wp_weight;
extern int ***wp_offset;
extern int listXsize[6];
extern int _usr_index;
extern int default_weight[3];
extern int list_offset;
extern int clist;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Introduce loop-carried dependence via cumulative indexing effect on memory updates
    int acc_weight[3] = {default_weight[0], default_weight[1], default_weight[2]};
    for (clist = 0; clist < 2 + list_offset; clist++) {
        for (index = 0; index < listXsize[clist]; index++) {
            // Create WAW hazard possibility by updating same default-like state across iterations
            // Simulate weight evolution: each write depends on prior iteration's side effect
            wp_weight[clist][index][0] = acc_weight[0];
            wp_weight[clist][index][1] = acc_weight[1];
            wp_weight[clist][index][2] = acc_weight[2];

            wp_offset[clist][index][0] = 0;
            wp_offset[clist][index][1] = 0;
            wp_offset[clist][index][2] = 0;

            // Loop-carried dependency: modify accumulator based on current index (creates artificial serial dependency)
            acc_weight[0] ^= (acc_weight[1] + index); // Feedback creates WAW/RAW loop-carried dep
            acc_weight[1] ^= (acc_weight[2] + clist);
            acc_weight[2] += 1;
        }
    }
}
