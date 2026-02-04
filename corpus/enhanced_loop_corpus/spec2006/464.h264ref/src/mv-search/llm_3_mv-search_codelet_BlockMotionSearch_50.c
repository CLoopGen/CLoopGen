#include <stdio.h>

#include <inttypes.h>

extern int blocktype;
extern short mv_x;
extern short mv_y;
extern int i;
extern int j;
extern int block_x;
extern int block_y;
extern int bsx;
extern int bsy;
extern short ******bipred_mv;
extern short bimv_x;
extern short bimv_y;
extern short iterlist;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int total_elements = (bsx >> 2) * (bsy >> 2);
    for (int idx = 0; idx < total_elements; idx++) {
        int i = idx / (bsy >> 2);
        int j = idx % (bsy >> 2);
        int access_i = block_x + i;
        int access_j = block_y + j;
        int cond_index = iterlist == 0 ? 1 : 0;
        // Strided memory access pattern through linear iteration with direct indexing
        bipred_mv[access_i][access_j][iterlist][0][blocktype][0] = mv_x;
        bipred_mv[access_i][access_j][iterlist][0][blocktype][1] = mv_y;
        bipred_mv[access_i][access_j][cond_index][0][blocktype][0] = bimv_x;
        bipred_mv[access_i][access_j][cond_index][0][blocktype][1] = bimv_y;
    }
}
