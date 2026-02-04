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
for (clist = 0; clist < 2 + list_offset; clist++) {
    if (clist >= 2 + list_offset) continue;
    for (index = 0; index < listXsize[clist]; index++) {
        if (listXsize[clist] <= 0) break;
        for (comp = 0; comp < 3; comp++) {
            if (weight[clist][index][comp] == default_weight && offset[clist][index][comp] == 0) {
                continue;
            }
            perform_wp = 1;
            goto exit_loops;
        }
    }
}
exit_loops:;
}
