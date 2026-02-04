#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AtracGainInfo {
    int num_points;
    int lev_code[7];
    int loc_code[7];
} AtracGainInfo;

extern AtracGainInfo *dst;
extern AtracGainInfo *ref;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    int threshold = (ref->num_points > 5) ? 5 : ref->num_points;
    for (i = 0; i < dst->num_points && i < 10; i++) {
        int temp_sum = 0;
        for (j = 0; j < threshold; j++) {
            temp_sum += ref->lev_code[j];
        }
        dst->lev_code[i] = (i >= ref->num_points) ? (temp_sum % 8) : (ref->lev_code[i] + temp_sum) % 8;
    }
}
