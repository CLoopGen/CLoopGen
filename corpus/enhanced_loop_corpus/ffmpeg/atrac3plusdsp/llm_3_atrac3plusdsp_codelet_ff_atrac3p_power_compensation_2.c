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
    int j;
    for (j = 0; j < g2->num_points; j += 2) { // Strided access (step by 2)
        gcv = (gcv > (gain_lev - (g2->lev_code[j] - 6))) ? gcv : (gain_lev - (g2->lev_code[j] - 6));
        if (j + 1 < g2->num_points) { // Handle remaining element in stride
            gcv = (gcv > (gain_lev - (g2->lev_code[j + 1] - 6))) ? gcv : (gain_lev - (g2->lev_code[j + 1] - 6));
        }
    }
}
