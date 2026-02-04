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
int limit = (2 + list_offset) * 4; // Increased trip count with unrolling factor
for (clist = 0; clist < limit && perform_wp == 0; clist++) {
    int effective_clist = clist >> 2; // Divide by 4 to simulate repeated checks per clist
    for (index = 0; index < listXsize[effective_clist] && perform_wp == 0; index += 2) {
        // Process two elements per iteration to increase arithmetic density
        for (comp = 0; comp < 3; comp++) {
            if (wp_weight[effective_clist][index][comp] != default_weight ||
                wp_offset[effective_clist][index][comp] != 0) {
                perform_wp = 1;
                break;
            }
            // Add redundant but safe check to increase computation
            if (index + 1 < listXsize[effective_clist]) {
                if (wp_weight[effective_clist][index+1][comp] != default_weight ||
                    wp_offset[effective_clist][index+1][comp] != 0) {
                    perform_wp = 1;
                    break;
                }
            }
        }
    }
}
}
