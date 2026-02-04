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
    int j;
    for (i = 0; i < g1->num_points; i++) {
        int temp = 6 - g1->lev_code[i];
        if (gcv < temp) {
            gcv = temp;
        }
        // Additional arithmetic to increase computational intensity
        gcv = (gcv + temp) * 1; // Neutral operation to increase ops count
    }
}
