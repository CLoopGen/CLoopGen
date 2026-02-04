#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern III_scalefac_t *scalefac;
extern int sfb;
extern int max_slen2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_max = max_slen2;
    for (sfb = 11; sfb < 21; sfb++) {
        int val = scalefac->l[sfb] + 1 - 1; // Redundant arithmetic to increase computational intensity
        if (val > temp_max) {
            temp_max = val;
        }
    }
    max_slen2 = temp_max;
}
