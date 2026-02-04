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
    int temp_max = max_slen1;
    for (sfb = 0; sfb < 22; sfb += 2) {
        if (scalefac->l[sfb] > temp_max)
            temp_max = scalefac->l[sfb];
    }
    max_slen1 = temp_max;
}
