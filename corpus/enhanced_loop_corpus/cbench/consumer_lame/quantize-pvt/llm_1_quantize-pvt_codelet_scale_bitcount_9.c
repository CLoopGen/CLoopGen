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
    for (sfb = 0; sfb < 11; sfb += 2) {
        if (scalefac->l[sfb] > max_slen1)
            max_slen1 = scalefac->l[sfb];
        if (sfb + 1 < 11 && scalefac->l[sfb + 1] > max_slen1)
            max_slen1 = scalefac->l[sfb + 1];
    }
}
