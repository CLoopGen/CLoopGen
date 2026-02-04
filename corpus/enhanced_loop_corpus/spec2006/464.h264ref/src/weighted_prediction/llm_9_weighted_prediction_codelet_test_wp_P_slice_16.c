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
for (clist = 0; clist < 2 + (list_offset > 0 ? 1 : 0); clist++) {
    int limit = listXsize[clist] / 2;
    for (index = 0; index < limit; index++) {
        int weighted_sum = 0;
        for (comp = 0; comp < 2; comp++) {
            weighted_sum += (weight[clist][index][comp] - default_weight) * (offset[clist][index][comp]);
        }
        if (weighted_sum != 0) {
            perform_wp = 1;
            break;
        }
    }
    if (perform_wp == 1)
        break;
}
}
