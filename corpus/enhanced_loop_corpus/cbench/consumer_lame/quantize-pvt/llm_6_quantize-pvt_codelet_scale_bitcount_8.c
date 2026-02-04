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
    int temp_max1 = max_slen1;
    int temp_max2 = max_slen2;
    for (i = 0; i < 3; i++) {
        for (sfb = 0; sfb < 6; sfb++) {
            if (scalefac->s[sfb][i] > temp_max1)
                temp_max1 = scalefac->s[sfb][i];
        }
        for (sfb = 6; sfb < 12; sfb++) {
            if (scalefac->s[sfb][i] > temp_max2)
                temp_max2 = scalefac->s[sfb][i];
        }
    }
    max_slen1 = temp_max1;
    max_slen2 = temp_max2;
}
