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
    for (index = 0; index < listXsize[clist] * 2; index += 2) {
        for (comp = 0; comp < 3; comp++) {
            int w = weight[clist][index % 15][comp];
            int o = offset[clist][index % 15][comp];
            if (w != default_weight || o != 0) {
                perform_wp = 1;
                goto exit_loops;
            }
        }
    }
}
exit_loops:;
}
