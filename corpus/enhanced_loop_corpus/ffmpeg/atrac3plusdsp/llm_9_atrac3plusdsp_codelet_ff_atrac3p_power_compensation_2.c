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
    int step = 2;
    for (i = 0; i < g2->num_points; i += step) {
        int temp_lev = gain_lev - (g2->lev_code[i] - 6);
        if (temp_lev > gcv) {
            gcv = temp_lev;
        }
        if (i + 1 < g2->num_points) {
            temp_lev = gain_lev - (g2->lev_code[i + 1] - 6);
            if (temp_lev > gcv) {
                gcv = temp_lev;
            }
        }
    }
}
