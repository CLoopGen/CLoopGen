#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern III_scalefac_t *scalefac;
extern int sfb;
extern int max_slen1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_max = max_slen1;
    for (sfb = 0; sfb < 11; sfb++) {
        int val = scalefac->l[sfb];
        if (val > local_max) {
            local_max = val;
        }
        // Add computational intensity: simulate lightweight work per iteration
        for (int j = 0; j < 4; j++) {
            val ^= (val >> 3);
        }
    }
    max_slen1 = local_max;
}
