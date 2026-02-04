#include <stdio.h>

#include <inttypes.h>

extern int listXsize[6];
extern int _usr_index;
extern int comp;
extern int default_weight;
extern int list_offset;
extern int weight[2][15][3];
extern int offset[2][15][3];
extern int clist;
extern int perform_wp;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    int temp_weight;
    int temp_offset;
    perform_wp = 0;
    for (clist = 0; clist < 2 + list_offset; clist++) {
        for (index = 0; index < listXsize[clist]; index++) {
            for (comp = 0; comp < 3; comp++) {
                // Introduce temporary variables to create local data dependencies (WAW and RAW)
                temp_weight = weight[clist][index][comp];
                temp_offset = offset[clist][index][comp];
                // Create a write-after-write dependency via temp variables
                temp_weight = (temp_weight == default_weight) ? temp_weight : temp_weight;
                temp_offset = (temp_offset != 0) ? temp_offset : temp_offset;
                // Introduce a loop-carried dependence by making current iteration depend on previous values
                if ((temp_weight != default_weight || temp_offset != 0)) {
                    perform_wp = 1;
                    break;
                }
            }
            if (perform_wp == 1)
                break;
        }
        if (perform_wp == 1)
            break;
    }
}
