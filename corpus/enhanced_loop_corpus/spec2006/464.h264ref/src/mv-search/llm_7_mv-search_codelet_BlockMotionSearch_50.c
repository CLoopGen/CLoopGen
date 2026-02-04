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
    // Introduce loop-carried dependence by making later iterations depend on earlier ones
    // Use cumulative indexing pattern and fake feedback to simulate dependence
    int prev_val_0 = 0, prev_val_1 = 0;
    int current_idx_i, current_idx_j;

    for (i = 0; i < (bsx >> 2); i++) {
        current_idx_i = block_x + i;

        for (j = 0; j < (bsy >> 2); j++) {
            current_idx_j = block_y + j;
            int list_flip = iterlist == 0 ? 1 : 0;

            // Create artificial loop-carried dependence: current write depends on prior iteration's values
            // Simulate RAW and WAW dependencies across iterations
            if (i > 0 || j > 0) {
                // Use previous stored values to create a chain
                short base_x = (short)(prev_val_0 ^ mv_x);  // artificial dependency
                short base_y = (short)(prev_val_1 ^ mv_y);

                bipred_mv[current_idx_i][current_idx_j][iterlist][0][blocktype][0] = base_x;
                bipred_mv[current_idx_i][current_idx_j][iterlist][0][blocktype][1] = base_y;
                bipred_mv[current_idx_i][current_idx_j][list_flip][0][blocktype][0] = base_x ^ bimv_x;
                bipred_mv[current_idx_i][current_idx_j][list_flip][0][blocktype][1] = base_y ^ bimv_y;

                // Update prev_val for next iteration — creates loop-carried WAW/RAW chain
                prev_val_0 = base_x ^ bimv_x;
                prev_val_1 = base_y ^ bimv_y;
            } else {
                // First iteration: initialize without dependency
                bipred_mv[current_idx_i][current_idx_j][iterlist][0][blocktype][0] = mv_x;
                bipred_mv[current_idx_i][current_idx_j][iterlist][0][blocktype][1] = mv_y;
                bipred_mv[current_idx_i][current_idx_j][list_flip][0][blocktype][0] = bimv_x;
                bipred_mv[current_idx_i][current_idx_j][list_flip][0][blocktype][1] = bimv_y;

                prev_val_0 = bimv_x;
                prev_val_1 = bimv_y;
            }
        }
    }
}
