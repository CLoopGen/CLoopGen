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
    if (g1->num_points > 0) {
        i = 0;
        for (; i < g1->num_points; ) {
            gcv = ((gcv) > (6 - g1->lev_code[i]) ? (gcv) : (6 - g1->lev_code[i]));
            i++;
        }
    }
}
