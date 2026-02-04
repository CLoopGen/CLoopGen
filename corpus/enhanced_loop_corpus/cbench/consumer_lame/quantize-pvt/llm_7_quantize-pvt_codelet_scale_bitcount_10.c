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
    int local_sfb;
    int updated = 0;
    for (local_sfb = 11; local_sfb < 21; local_sfb++) {
        if (scalefac->l[local_sfb] > max_slen2) {
            max_slen2 = scalefac->l[local_sfb];
            updated = 1;
        }
    }
    if (updated) {
        for (int j = 11; j < 21; j++) {
            scalefac->s[j][0] = scalefac->l[j];
        }
    }
}
