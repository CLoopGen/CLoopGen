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
int trip_count = (bsx >> 3) * (bsy >> 3);
for (i = 0; i < trip_count; i++) {
    int flat_i = i / (bsy >> 3);
    int flat_j = i % (bsy >> 3);
    int real_i = (block_x + flat_i) << 1;
    int real_j = (block_y + flat_j) << 1;

    for (int di = 0; di < 2; di++) {
        for (int dj = 0; dj < 2; dj++) {
            int access_i = real_i + di;
            int access_j = real_j + dj;
            int flip_iter = iterlist ^ 1;

            bipred_mv[access_i][access_j][iterlist][0][blocktype][0] = mv_x;
            bipred_mv[access_i][access_j][iterlist][0][blocktype][1] = mv_y;
            bipred_mv[access_i][access_j][flip_iter][0][blocktype][0] = bimv_x;
            bipred_mv[access_i][access_j][flip_iter][0][blocktype][1] = bimv_y;
        }
    }
}
}
