#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AtracGainInfo {
    int num_points;
    int lev_code[7];
    int loc_code[7];
} AtracGainInfo;

extern AtracGainInfo *g2;
extern int i;
extern int gain_lev;
extern int gcv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_gcv = gcv;
    for (i = 0; i < g2->num_points; i++) {
        int lev_diff = gain_lev - (g2->lev_code[i] - 6);
        if (lev_diff > temp_gcv) {
            temp_gcv = lev_diff;
        }
    }
    gcv = temp_gcv;
}
