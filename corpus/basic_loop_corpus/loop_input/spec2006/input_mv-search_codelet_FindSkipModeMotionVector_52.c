#include <inttypes.h>
#include <stdlib.h>

int bx;
int by;

short ******all_mv;

void init_vars() {
    // Allocate a 4x4 base array for the first two dimensions since bx,by go from 0 to 3
    all_mv = (short******)calloc(4, sizeof(short*****));
    for (int i = 0; i < 4; i++) {
        all_mv[i] = (short*****)calloc(4, sizeof(short****));
        for (int j = 0; j < 4; j++) {
            // For the remaining 4 dimensions, we only need [0][0][0][0] and [0][0][0][1]
            // But we must allocate at least one entry at each level
            all_mv[i][j] = (short****)calloc(1, sizeof(short***));
            all_mv[i][j][0] = (short***)calloc(1, sizeof(short**));
            all_mv[i][j][0][0] = (short**)calloc(1, sizeof(short*));
            all_mv[i][j][0][0][0] = (short*)calloc(2, sizeof(short)); // Only need indices 0 and 1
        }
    }
}