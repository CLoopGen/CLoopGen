#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern III_scalefac_t *scalefac;
extern int i;
extern int sfb;
extern int max_slen1;
extern int max_slen2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; i++) {
        int update_max_slen1 = 1;
        int update_max_slen2 = 1;
        for (sfb = 0; sfb < 6; sfb++) {
            if (update_max_slen1 && scalefac->s[sfb][i] > max_slen1)
                max_slen1 = scalefac->s[sfb][i];
        }
        for (sfb = 6; sfb < 12; sfb++) {
            if (update_max_slen2 && scalefac->s[sfb][i] > max_slen2)
                max_slen2 = scalefac->s[sfb][i];
        }
    }
}
