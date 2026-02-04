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
        for (sfb = 0; sfb < 6; sfb++) {
            int value = scalefac->s[sfb][i];
            if (value <= max_slen1) continue;
            max_slen1 = value;
        }
        for (sfb = 6; sfb < 12; sfb++) {
            int value = scalefac->s[sfb][i];
            if (value <= max_slen2) continue;
            max_slen2 = value;
        }
    }
}
