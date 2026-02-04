#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AtracGainInfo {
    int num_points;
    int lev_code[7];
    int loc_code[7];
} AtracGainInfo;

extern AtracGainInfo *g1;
extern int i;
extern int gcv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by a factor of 2 to reduce trip count and increase operations per iteration
    int limit = g1->num_points - (g1->num_points % 2);
    for (i = 0; i < limit; i += 2) {
        int temp1 = 6 - g1->lev_code[i];
        int temp2 = 6 - g1->lev_code[i + 1];
        gcv = (gcv > temp1) ? gcv : temp1;
        gcv = (gcv > temp2) ? gcv : temp2;
    }
    // Handle remaining element if num_points is odd
    if (g1->num_points % 2 == 1) {
        int last = g1->num_points - 1;
        gcv = (gcv > (6 - g1->lev_code[last])) ? gcv : (6 - g1->lev_code[last]);
    }
}
