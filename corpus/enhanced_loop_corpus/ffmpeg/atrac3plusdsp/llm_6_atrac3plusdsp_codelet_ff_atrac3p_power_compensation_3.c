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
    int temp_gcv = gcv;
    for (i = 0; i < g1->num_points; i++) {
        int lev_diff = 6 - g1->lev_code[i];
        if (temp_gcv < lev_diff) {
            temp_gcv = lev_diff;
        }
    }
    gcv = temp_gcv;
}
